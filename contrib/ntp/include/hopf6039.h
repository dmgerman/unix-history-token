begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*      hopf6039.h                                                          */
end_comment

begin_comment
comment|/*      hopf Elektronik 6039 PCI radio clock header                         */
end_comment

begin_comment
comment|/*      (c) 1999, 2000 Bernd Altmeier<altmeier@ATLSoft.de>              */
end_comment

begin_comment
comment|/*      Rev. 1.00 Date 25.03.2000                                           */
end_comment

begin_comment
comment|/*      History:                                                            */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_hopf6039_H_
end_ifndef

begin_define
define|#
directive|define
name|_hopf6039_H_
end_define

begin_define
define|#
directive|define
name|HOPF_MAXVERSION
value|8
end_define

begin_define
define|#
directive|define
name|HOPF_CNTR_MEM_LEN
value|0x7f
end_define

begin_define
define|#
directive|define
name|HOPF_DATA_MEM_LEN
value|0x3ff
end_define

begin_comment
comment|/* this is our memory size */
end_comment

begin_comment
comment|/* macros and definition for 32 to 16 to 8 bit conversion */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|DWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|WORD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOWORD
parameter_list|(
name|l
parameter_list|)
value|((WORD)(l))
end_define

begin_define
define|#
directive|define
name|HIWORD
parameter_list|(
name|l
parameter_list|)
value|((WORD)(((DWORD)(l)>> 16)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|LOBYTE
parameter_list|(
name|w
parameter_list|)
value|((BYTE)(w))
end_define

begin_define
define|#
directive|define
name|HIBYTE
parameter_list|(
name|w
parameter_list|)
value|((BYTE)(((WORD)(w)>> 8)& 0xFF))
end_define

begin_comment
comment|/* iocntl codes for driver access */
end_comment

begin_define
define|#
directive|define
name|HOPF_CLOCK_CMD_MASK
value|0xff000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_LOCAL
value|0x10000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_UTC
value|0x20000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_ANTENNA
value|0x30000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_DIFFERENCE
value|0x40000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_VERSION
value|0x50000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_POSITION
value|0x60000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_SATDATA
value|0x70000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_SYSTEMBYTE
value|0x80000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_GET_IRIG
value|0x90000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_DIFFERENCE
value|0x01000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_ANTENNA
value|0x02000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_TIME
value|0x03000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_POSITION
value|0x04000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_SATMODE
value|0x05000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_SYSTEMBYTE
value|0x06000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_RESET
value|0x07000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SET_IRIG
value|0x08000
end_define

begin_comment
comment|/* clock command codes */
end_comment

begin_define
define|#
directive|define
name|HOPF_CLOCK_HARDRESET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HOPF_CLOCK_SOFTRESET
value|0x00004000
end_define

begin_comment
comment|/* sat-information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|SatStat
block|{
name|BYTE
name|wVisible
decl_stmt|;
name|BYTE
name|wMode
decl_stmt|;
name|BYTE
name|wSat0
decl_stmt|;
name|BYTE
name|wRat0
decl_stmt|;
name|BYTE
name|wSat1
decl_stmt|;
name|BYTE
name|wRat1
decl_stmt|;
name|BYTE
name|wSat2
decl_stmt|;
name|BYTE
name|wRat2
decl_stmt|;
name|BYTE
name|wSat3
decl_stmt|;
name|BYTE
name|wRat3
decl_stmt|;
name|BYTE
name|wSat4
decl_stmt|;
name|BYTE
name|wRat4
decl_stmt|;
name|BYTE
name|wSat5
decl_stmt|;
name|BYTE
name|wRat5
decl_stmt|;
name|BYTE
name|wSat6
decl_stmt|;
name|BYTE
name|wRat6
decl_stmt|;
name|BYTE
name|wSat7
decl_stmt|;
name|BYTE
name|wRat7
decl_stmt|;
block|}
name|SatStat
typedef|;
end_typedef

begin_comment
comment|/* GPS position */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|GPSPos
block|{
comment|/* Position */
name|long
name|wAltitude
decl_stmt|;
name|long
name|wLongitude
decl_stmt|;
name|long
name|wLatitude
decl_stmt|;
block|}
name|GPSPos
typedef|;
end_typedef

begin_comment
comment|/* clock hardware version */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ClockVersion
block|{
name|char
name|cVersion
index|[
literal|255
index|]
decl_stmt|;
comment|/* Hardware Version like " DCF-RECEIVER,   VERSION 01.01, DAT: 23.NOV.1999" */
name|char
name|dVersion
index|[
literal|255
index|]
decl_stmt|;
comment|/* Driver Version */
block|}
name|ClockVersion
typedef|;
end_typedef

begin_comment
comment|/* hopftime what you think */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HOPFTIME
block|{
name|unsigned
name|int
name|wYear
decl_stmt|;
name|unsigned
name|int
name|wMonth
decl_stmt|;
name|unsigned
name|int
name|wDayOfWeek
decl_stmt|;
name|unsigned
name|int
name|wDay
decl_stmt|;
name|unsigned
name|int
name|wHour
decl_stmt|;
name|unsigned
name|int
name|wMinute
decl_stmt|;
name|unsigned
name|int
name|wSecond
decl_stmt|;
name|unsigned
name|int
name|wMilliseconds
decl_stmt|;
name|unsigned
name|int
name|wStatus
decl_stmt|;
block|}
name|HOPFTIME
typedef|;
end_typedef

begin_comment
comment|/* DCF77 antenna alignment */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DcfAntenne
block|{
name|BYTE
name|bStatus
decl_stmt|;
name|BYTE
name|bStatus1
decl_stmt|;
name|WORD
name|wAntValue
decl_stmt|;
block|}
name|DcfAntenne
typedef|;
end_typedef

begin_comment
comment|/* hopf PCI clock */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hopfCard
block|{
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|irq
decl_stmt|;
name|unsigned
name|long
name|membase
decl_stmt|;
comment|/* without mmap */
name|unsigned
name|int
name|port
decl_stmt|;
name|int
name|versionlen
decl_stmt|;
name|char
name|versionbuf
index|[
literal|1024
index|]
decl_stmt|;
name|char
modifier|*
name|version
index|[
name|HOPF_MAXVERSION
index|]
decl_stmt|;
name|char
name|cardname
index|[
literal|32
index|]
decl_stmt|;
name|int
name|interrupt
decl_stmt|;
name|void
modifier|*
name|mbase
decl_stmt|;
comment|/* this will be our memory base address */
block|}
name|hopfCard
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cardparams
block|{
name|unsigned
name|int
name|port
decl_stmt|;
name|unsigned
name|irq
decl_stmt|;
name|int
name|cardtype
decl_stmt|;
name|int
name|cardnr
decl_stmt|;
name|unsigned
name|int
name|membase
decl_stmt|;
block|}
name|cardparams
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WRITE_REGISTER
value|0x00
end_define

begin_define
define|#
directive|define
name|READ_REGISTER
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _hopf6039_H_ */
end_comment

end_unit

