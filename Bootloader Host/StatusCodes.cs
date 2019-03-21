using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bootloader_Host
{
    public enum StatusCodes
    {
        CYRET_SUCCESS = 0,
        CYRET_ERR_FILE = 1,
        CYRET_ERR_EOF = 2,
        CYRET_ERR_LENGTH = 3,
        CYRET_ERR_DATA = 4,
        CYRET_ERR_CMD = 5,
        CYRET_ERR_DEVICE = 6,
        CYRET_ERR_VERSION = 7,
        CYRET_ERR_CHECKSUM = 8,
        CYRET_ERR_ARRAY = 9,
        CYRET_ERR_ROW = 10,
        CYRET_ERR_BTLDR = 11,
        CYRET_ERR_ACTIVE = 12,
        CYRET_ERR_UNKNOWN = 15,
        CYRET_ABORT = 255,
        CYRET_ERR_COMM_MASK = 8192,
        CYRET_ERR_BTLDR_MASK = 16384,
    }
}
