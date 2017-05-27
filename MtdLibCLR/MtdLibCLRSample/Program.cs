using MtdLibCLR;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MtdLibCLRSample
{
    class Program
    {
        static void Main(string[] args)
        {
#if false
            using (var mtd = new MtdLib())
            {
                if (!mtd.IsRead)
                {
                    if (mtd.Read(@"***.mtd"))
                    {
                        mtd.Write(@"before.mtd");
                        _Proc(mtd);
                        mtd.Write(@"after.mtd");
                    }
                }
            }
            using (var mtd = new MtdLib())
            {
                Console.WriteLine("{0}{0}{0}", Environment.NewLine);
                mtd.Read(@"***.mtd");
                _Dump(mtd);
                _Proc(mtd);
                _Dump(mtd);
            }
#endif

            using (var mtd = new MtdLib())
            {
                mtd.Read(@"***.mtd");
                mtd.Write(@"***.mtd");
                Console.WriteLine("{0}{0}{0}", Environment.NewLine);
                string spx;
                mtd.Read(@"before.mtd");
                if (mtd.GetSPXPath(out spx))
                {
                    Console.WriteLine($"SPX:\t{spx}");
                }
                List<string> paramList = _GetParamNames(spx);
                Dictionary<string, dynamic> values = new Dictionary<string, dynamic>();
                values["g_diffuseMapColor"] = new float[3];
                values["param1"] = new float[4];
                values["param2"] = new int[4];
                values["param3"] = new bool[2];
                foreach (var param in paramList)
                {
                    mtd.GetParam(param, values[param]);
                }
                List<string> texmapList = _GetTexmapNames(spx);
                foreach (var texmap in texmapList)
                {
                    var uv = new float[2];
                    string path;
                    if (mtd.GetTexmap(texmap, out path, uv))
                    {
                        values[texmap] = Tuple.Create(path, uv);
                    }
                }

                foreach (var pair in values)
                {
                    var name = pair.Key;
                    var value = pair.Value;
                    var tuple = value as Tuple<string, float[]>;
                    if (null != tuple)
                    {
                        // Tex
                        var s = tuple.Item1;
                        var v2 = tuple.Item2;
                        Console.WriteLine($"{name}: ({v2[0]:f4}, {v2[1]:f4}) {s}");

                    }
                    else
                    {
                        // Param
                        Console.WriteLine($"{name}:( {string.Join(", ", value)})");
                    }
                }
                string line;
                while ((line = Console.ReadLine()) != "END.")
                {
                    var token = line.Split('=');
                    var name = token[0].Trim();
                    var value = token[1].Trim();
                    var old = values[name];
                    if (old is int[])
                    {
                        values[name] = Array.ConvertAll(value.Split(','), s => int.Parse(s.Trim()));
                    }
                    else if (old is float[])
                    {
                        values[name] = Array.ConvertAll(value.Split(','), s => float.Parse(s.Trim()));
                    }
                    else if (old is bool[])
                    {
                        
                        values[name] = Array.ConvertAll(value.Split(','), s => bool.Parse(s.Trim()));
                    }
                    else if (old is Tuple<string, float[]>)
                    {
                        var t = value.Split(':').Select(s => s.Trim()).ToList();
                        if (string.Equals(t[0], "p", StringComparison.InvariantCultureIgnoreCase))
                        {
                            values[name] = Tuple.Create(t[1], values[name].Item2);
                        }
                        else if (string.Equals(t[0], "t", StringComparison.InvariantCultureIgnoreCase))
                        {
                            values[name] = Tuple.Create(values[name].Item1, Array.ConvertAll(t[1].Split(','), s => float.Parse(s.Trim())));
                        }
                    }
                }

                {
                    foreach(var param in paramList)
                    {
                        mtd.SetParam(param, values[param]);
                    }
                    foreach(var texmap in texmapList)
                    {
                        Tuple<string, float[]> v = values[texmap];
                        mtd.SetTexmap(texmap, v.Item1, v.Item2[0], v.Item2[1]);
                    }
                }

                mtd.Write(@"after.mtd");

            }

            Console.WriteLine("end.");
            Console.ReadKey();
        }

        private static List<string> _GetTexmapNames(string spx)
        {
            var list = new List<string>();

            list.Add("g_AlbedoMap");
            list.Add("g_NormalMap");
            list.Add("g_ShininessMap");
            list.Add("g_AlbedoMap1");

            return list;
        }

        private static List<string> _GetParamNames(string spx)
        {
            var list = new List<string>();

            list.Add("g_diffuseMapColor");
            list.Add("param1");
            list.Add("param2");
            list.Add("param3");

            return list;
        }

        private static void _Dump(MtdLib mtd)
        {
            var v2 = new float[2];
            var v3 = new float[3];
            var v4 = new float[4];
            var i3 = new int[3];
            var b2 = new bool[2];
            var s = string.Empty;

            foreach (var pair in new[]{
                new { Name = "g_diffuseMapColor", V = (dynamic)v3 },
                new { Name = "param1", V = (dynamic)v4 },
                new { Name = "param2", V = (dynamic)i3 },
                new { Name = "param3", V = (dynamic)b2 },
            })
            {
                if (mtd.GetParam(pair.Name, pair.V))
                {
                    Console.WriteLine($"{pair.Name}:( {string.Join(", ", pair.V)})");
                }
            }

            foreach (var name in new[] { "g_AlbedoMap", "g_NormalMap", "g_ShininessMap" })
            {
                if (mtd.GetTexmap(name, out s, v2))
                {
                    Console.WriteLine($"{name}: ({v2[0]:f4}, {v2[1]:f4}) {s}");
                }
            }
        }

        private static void _Proc(MtdLib mtd)
        {
            {
                mtd.SetParam("g_diffuseMapColor", new float[] { 1f, 0.4f, 0.3f });
                mtd.SetParam("param1", new float[] { 1f, 0.4f, 0.3f, 0.7f });
                mtd.SetParam("param2", new int[] { 255, 255, 255, });
                mtd.SetParam("param3", new bool[] { true, false });
            }
            {
                mtd.SetTexmap("g_AlbedoMap", "000_a.tif", 1.0f, 1.0f);
                mtd.SetTexmap("g_NormalMap", "000_n.tif", 2.0f, 2.0f);
                mtd.SetTexmap("g_ShininessMap", "000_s.tif", 10.0f, 10.0f);
            }
        }
    }
    
}
