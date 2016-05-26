﻿using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication1
{
    public class Vertex
    {
        public string Name;
        public int x;
        public int y;

        public bool isUsed;
        internal bool selected;
    }

    public class Edge
    {
        public Vertex ver1;
        public Vertex ver2;

        public bool selected;

        public Edge(Vertex v1, Vertex v2)
        {
            ver1 = v1;
            ver2 = v2;

            v1.isUsed = true;
            v2.isUsed = true;
        }
    }

    class GraphOrlov
    {
        public List<Vertex> Vertexes = new List<Vertex>();
        public List<Edge> Edges = new List<Edge>();
        private int verCount;
        const int step = 80;

        public GraphOrlov(int verCount)
        {
            this.verCount = verCount;

            for (int i = 0; i < verCount; ++i)
            {
                var new_ver = new Vertex();
                new_ver.Name = "X" + (Vertexes.Count + 1);

                if (Vertexes.Count == 0)
                {
                    new_ver.x = step;
                    new_ver.y = step/2;
                }
                else
                {
                    new_ver.x = Vertexes.Last().x + step / 2;
                    new_ver.y =  step/2;
                }

                Vertexes.Add(new_ver);
            }
        }

        public void Render(Graphics g)
        {
            g.SmoothingMode = SmoothingMode.HighQuality;
            int R = 15;
            var Pen = new Pen(Color.Black, 2);
            var SelPen = new Pen(Color.Red, 2);

            foreach (Vertex vertex in Vertexes)
            {
                g.DrawEllipse(Pen, new Rectangle(vertex.x - R, vertex.y - R, R*2, R*2));

                g.DrawString(vertex.Name, SystemFonts.DefaultFont, Brushes.Black, new PointF(vertex.x - R/2, vertex.y - R/2));
            }

            foreach (var edge in Edges)
            {
                //arrow
                var arrowpen = Pen;
                var ver1 = edge.ver1;
                var ver2 = edge.ver2;
                var r1 = 15;
                var r2 = 20;
                if ((ver2.x - ver1.x) == 0 && (ver2.y - ver1.y) == 0)
                {
                    arrowpen = new Pen(Color.Red);
                    r1 = 10;
                    r2 = 25;
                }
                double ugolstrelki = Math.Atan2(ver2.x - ver1.x, ver2.y - ver1.y);
                g.DrawLine(arrowpen, 
                    Convert.ToInt32(ver2.x + r1 * Math.Sin(ugolstrelki + 3.1516) + r2 * Math.Sin(ugolstrelki + 3.5)), 
                    Convert.ToInt32(ver2.y + r1 * Math.Cos(ugolstrelki + 3.1516) + r2 * Math.Cos(ugolstrelki + 3.5)),
                    Convert.ToInt32(ver2.x + r1 * Math.Sin(ugolstrelki + 3.1516)), 
                    Convert.ToInt32(ver2.y + r1 * Math.Cos(ugolstrelki + 3.1516)));
                g.DrawLine(arrowpen, 
                    Convert.ToInt32(ver2.x + r1 * Math.Sin(ugolstrelki + 3.1516) + r2 * Math.Sin(ugolstrelki - 3.5)), 
                    Convert.ToInt32(ver2.y + r1 * Math.Cos(ugolstrelki + 3.1516) + r2 * Math.Cos(ugolstrelki - 3.5)),
                    Convert.ToInt32(ver2.x + r1 * Math.Sin(ugolstrelki + 3.1516)), 
                    Convert.ToInt32(ver2.y + r1 * Math.Cos(ugolstrelki + 3.1516)));
 

                //edge
                g.DrawLine(Pen, edge.ver1.x, edge.ver1.y, edge.ver2.x, edge.ver2.y);

                g.FillEllipse(Brushes.White, new Rectangle(edge.ver1.x - R, edge.ver1.y - R, R * 2, R * 2)); // вынести отдельной функцией
                g.DrawEllipse(edge.ver1.selected ? SelPen : Pen, new Rectangle(edge.ver1.x - R, edge.ver1.y - R, R*2, R*2));
                g.DrawString(edge.ver1.Name, SystemFonts.DefaultFont, Brushes.Black, new PointF(edge.ver1.x - R / 2, edge.ver1.y - R / 2));

                g.FillEllipse(Brushes.White, new Rectangle(edge.ver2.x - R, edge.ver2.y - R, R*2, R*2));
                g.DrawEllipse(edge.ver2.selected ? SelPen : Pen, new Rectangle(edge.ver2.x - R, edge.ver2.y - R, R * 2, R * 2));
                g.DrawString(edge.ver2.Name, SystemFonts.DefaultFont, Brushes.Black, new PointF(edge.ver2.x - R / 2, edge.ver2.y - R / 2));
            }
        }
    }
}
