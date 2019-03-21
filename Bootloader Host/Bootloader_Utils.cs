// Decompiled with JetBrains decompiler
// Type: USBBootloaderHost.Bootloader_Utils
// Assembly: USBBootloaderHost, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null
// MVID: 9B83FDAC-55C4-496F-927D-E7B27114F6F7
// Assembly location: C:\Kate\Ghett-IO\Firmware Upgrader\Firmware Upgrader.exe

using System;
using System.Runtime.InteropServices;

namespace Bootloader_Host
{
    internal class Bootloader_Utils
    {
        [DllImport("BootLoader_Utils.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int CyBtldr_Program(string file, byte[] securityKey, byte appId, ref Bootloader_Utils.CyBtldr_CommunicationsData comm, Bootloader_Utils.CyBtldr_ProgressUpdate update);

        public struct CyBtldr_CommunicationsData
        {
            public Bootloader_Utils.OpenConnection_USB OpenConnection;
            public Bootloader_Utils.CloseConnection_USB CloseConnection;
            public Bootloader_Utils.ReadData_USB ReadData;
            public Bootloader_Utils.WriteData_USB WriteData;
            public uint MaxTransferSize;
        }

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int OpenConnection_USB();

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int CloseConnection_USB();

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int ReadData_USB(IntPtr buffer, int size);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int WriteData_USB(IntPtr buffer, int size);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void CyBtldr_ProgressUpdate(byte arrayID, ushort rowNum);
    }
}
