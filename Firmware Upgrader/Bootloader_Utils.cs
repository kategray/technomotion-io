using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace USBBootloaderHost 
{
    class Bootloader_Utils
    {
        /// <summary>
        /// Structure used to pass communication data down to the unmanged native C code
        /// that handles the bootloading operations.
        /// </summary>
        [StructLayout(LayoutKind.Sequential)]
        public struct CyBtldr_CommunicationsData 
        {
            /// <summary>
            /// Function used to open the communications connection
            /// </summary>
            public OpenConnection_USB OpenConnection;
            /// <summary>
            /// Function used to close the communications connection
            /// </summary>
            public CloseConnection_USB CloseConnection;
            /// <summary>
            /// Function used to read data over the communications connection
            /// </summary>
            public ReadData_USB ReadData;
            /// <summary>
            /// Function used to write data over the communications connection
            /// </summary>
            public WriteData_USB WriteData;
            /// <summary>
            /// Value used to specify the maximum number of bytes that can be trasfered at a time
            /// </summary>
            public uint MaxTransferSize;
        };
        
        /// <summary>
                  /// Delegate used as a callback from native code for opening a communications connection
                  /// </summary>
                  /// <returns>Integer representing success == 0 or failure </returns>
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int OpenConnection_USB();

        /// <summary>
        /// Delegate used as a callback from native code for closing a communications connection
        /// </summary>
        /// <returns>Integer representing success == 0 or failure </returns>
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int CloseConnection_USB();

        /// <summary>
        /// Delegate used as a callback from native code for reading data from a communications connection
        /// </summary>
        /// <param name="buffer">The buffer to store the read data in</param>
        /// <param name="size">The number of bytes of data to read</param>
        /// <returns>Integer representing success == 0 or failure </returns>
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int ReadData_USB(IntPtr buffer, int size);

        /// <summary>
        /// Delegate used as a callback from native code for writing data over a communications connection
        /// </summary>
        /// <param name="buffer">The buffer containing data to write</param>
        /// <param name="size">The number of bytes to write</param>
        /// <returns>Integer representing success == 0 or failure </returns>
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int WriteData_USB(IntPtr buffer, int size);

        /// <summary>
        /// Delegate used as a callback from native code for notifying that a row is complete
        /// </summary>
        /// <param name="arrayID">The array ID that was accessed</param>
        /// <param name="rowNum">The row number within the array that was accessed</param>
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate void CyBtldr_ProgressUpdate(byte arrayID, ushort rowNum);


        [DllImport("BootLoader_Utils.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int CyBtldr_Program(string file, byte[] securityKey, byte appId, ref CyBtldr_CommunicationsData comm, CyBtldr_ProgressUpdate update);
    }
}
