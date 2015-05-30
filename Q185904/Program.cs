using System;
using System.Diagnostics;
using System.Threading;

namespace Q185904
{
	public class Worker
	{
		private Process m_p;

		public Worker(Process p)
		{
			this.m_p = p;
		}

		// This method will be called when the thread is started.
		public void DoWork()
		{
			while (!_shouldStop)
			{
				Console.WriteLine("worker thread: working...");
				if (Console.KeyAvailable)
					break;
			}
			Console.WriteLine("worker thread: terminating gracefully.");
			if (!this.m_p.HasExited)
				this.m_p.Kill();
		}

		public void RequestStop()
		{
			_shouldStop = true;
		}

		// Volatile is used as hint to the compiler that this data
		// member will be accessed by multiple threads.
		private volatile bool _shouldStop;
	}

	internal class Program
	{
		private static void Main(string[] args)
		{
			var p = Process.Start("C:\\Windows\\notepad.exe");
			p.WaitForInputIdle();
			var w = new Worker(p);
			var t = new Thread(w.DoWork);
			t.Start();
			if (!p.HasExited)
				p.WaitForExit();
			w.RequestStop();
		}
	}
}