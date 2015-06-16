using System;

namespace Q189396
{
	internal class Program
	{
		private static void sub(int n)
		{
			var inst = Sample.Instance;
			for (int i = 0; i < n; i++)
				inst.visit();
			Console.WriteLine("Sub:Count={0}", inst.VisitCount);
		}

		private static void Main(string[] args)
		{
			var inst = Sample.Instance;
			inst.visit();
			Console.WriteLine("Main:Count={0}", inst.VisitCount);

			sub(10);

			inst.visit();
			Console.WriteLine("Main:Count={0}", inst.VisitCount);

			Console.ReadLine();
		}
	}

	internal class Sample
	{
		private static Sample m_instance;
		private static object thisObject = new object();

		public static Sample Instance
		{
			get
			{
				if (m_instance == null)
				{
					lock (thisObject)
					{
						if (m_instance == null)
						{
							m_instance = new Sample();
						}
					}
				}
				return m_instance;
			}
		}

		private int m_count = 0;

		private Sample()
		{
		}

		public int VisitCount { get { return this.m_count; } }

		public void visit()
		{
			this.m_count++;
		}
	}
}