begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ******************************  trlld.h  ***********************************  *  *                          Copyright (c) 1997  *                          OLICOM A/S  *                          Denmark  *  *                          All Rights Reserved  *  *      This source file is subject to the terms and conditions of the  *      OLICOM Software License Agreement which restricts the manner  *      in which it may be used.  *  *---------------------------------------------------------------------------  *  * Description: PowerMACH Works header file  * $FreeBSD$  *  *---------------------------------------------------------------------------  * $Log:   J:/usr/project/trlld/libsrc/include/trlld.h_v  $  *   *    Rev 1.9   25 Jan 1999 09:56:28   EGS  * Added 3150  *   *    Rev 1.8   10 Dec 1998 12:24:52   JHM  * version 1.2.0,prominfo structure with shorts.  *   *    Rev 1.7   25 Nov 1998 16:18:48   JHM  * Bullseye mac, 100MBPS, mactype in config structure,  * 3540 adapter, TRlldTransmitFree, TRlldReceiveFree,  * TRlldAdapterName  *   *    Rev 1.6   23 Oct 1998 16:00:36   JHM  * hawkeye adapter types  *   *    Rev 1.5   11 Aug 1998 12:22:06   JHM  * split hawkeye types into PCI4,5,6  *   *    Rev 1.4   10 Jul 1998 14:39:22   JHM  * OC_3140,OC_3250  *   *    Rev 1.3   18 Jun 1998 11:32:20   JHM  * AddMemory,OC_3250  *   *    Rev 1.2   18 Apr 1998 15:11:20   JHM  *   *    Rev 1.1   09 Dec 1997 18:17:52   JHM  * rel111: TRlldDataPtr_t  *   *    Rev 1.0   24 Nov 1997 11:08:58   JHM  * Initial revision.           Rev 1.5   18 Jun 1997 11:31:36   JHM    Checks for version           Rev 1.4   13 Jun 1997 13:47:34   JHM           Rev 1.3   13 Jun 1997 13:27:56   JHM    DTR support, version change           Rev 1.2   12 Jun 1997 11:43:20   JHM    TRLLD_INTERRUPT_TIMEOUT defined           Rev 1.1   11 Apr 1997 15:24:18   JHM    replaced tabs with spaces           Rev 1.0   11 Apr 1997 14:43:04   JHM    Initial revision.  *  **************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRLLD_H
end_ifndef

begin_define
define|#
directive|define
name|TRLLD_H
end_define

begin_comment
comment|/* Data buffer pointers are always 32 bits.    For 16:16 it is segment:offset while it for 32:32 is a linear address. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRlldSmall
end_ifdef

begin_define
define|#
directive|define
name|TRlldDataPtr_t
value|unsigned char far *
end_define

begin_define
define|#
directive|define
name|TRlldWordDataPtr_t
value|unsigned short far *
end_define

begin_define
define|#
directive|define
name|TRlldDWordDataPtr_t
value|unsigned long far *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRlldDataPtr_t
value|unsigned char *
end_define

begin_define
define|#
directive|define
name|TRlldWordDataPtr_t
value|unsigned short *
end_define

begin_define
define|#
directive|define
name|TRlldDWordDataPtr_t
value|unsigned long *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__WATCOMC__
end_ifdef

begin_define
define|#
directive|define
name|CDECL
value|_cdecl
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CDECL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Firmware                                                                  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|TRlldMacCode
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3115,17,18,29,33,36,37 */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|TRlldHawkeyeMac
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3139,3140,3141,3250    */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|TRlldBullseyeMac
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 3150,3540              */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Maximal numbers of concurrent receive and transmit slots                  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TRLLD_MAX_RECEIVE
value|32
end_define

begin_define
define|#
directive|define
name|TRLLD_MAX_TRANSMIT
value|32
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Maximal frame sizes                                                       */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|TRLLD_MAXFRAME_100MBPS
value|18000
end_define

begin_define
define|#
directive|define
name|TRLLD_MAXFRAME_16MBPS
value|18000
end_define

begin_define
define|#
directive|define
name|TRLLD_MAXFRAME_4MBPS
value|4500
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* TRlldStatus contains the adapter status used in a DriverStatus call-back. */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_struct
struct|struct
name|OnWireInformation
block|{
name|unsigned
name|short
name|RingStatus
decl_stmt|;
name|unsigned
name|short
name|Speed
decl_stmt|;
name|unsigned
name|short
name|AccessProtocol
decl_stmt|;
name|unsigned
name|short
name|Reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|TRlldStatus
block|{
name|unsigned
name|short
name|Type
decl_stmt|;
name|unsigned
name|char
name|Closed
decl_stmt|;
name|unsigned
name|char
name|AccessProtocol
decl_stmt|;
name|unsigned
name|short
name|MaxFrameSize
decl_stmt|;
name|unsigned
name|short
name|Reserved
decl_stmt|;
union|union
block|{
name|unsigned
name|short
name|OnWireRingStatus
decl_stmt|;
comment|/* for compability */
name|unsigned
name|short
name|SelftestStatus
decl_stmt|;
name|unsigned
name|short
name|InitStatus
decl_stmt|;
name|unsigned
name|short
name|RingStatus
decl_stmt|;
name|unsigned
name|short
name|AdapterCheck
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|InternalError
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|PromRemovedCause
decl_stmt|;
name|unsigned
name|short
name|AdapterTimeout
decl_stmt|;
name|struct
name|OnWireInformation
name|OnWireInformation
decl_stmt|;
block|}
name|Specification
union|;
block|}
name|TRlldStatus_t
typedef|;
end_typedef

begin_comment
comment|/* values of TRlldStatus.Type */
end_comment

begin_define
define|#
directive|define
name|TRLLD_STS_ON_WIRE
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_SELFTEST_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_INIT_STATUS
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_RING_STATUS
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_ADAPTER_CHECK
value|4
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_PROMISCUOUS_STOPPED
value|5
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_LLD_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_ADAPTER_TIMEOUT
value|7
end_define

begin_comment
comment|/* values of TRlldStatus.Closed */
end_comment

begin_define
define|#
directive|define
name|TRLLD_STS_STATUS_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_STS_STATUS_CLOSED
value|1
end_define

begin_comment
comment|/* values of TRlldStatus.AccessProtocol */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ACCESS_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_ACCESS_TKP
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_ACCESS_TXI
value|2
end_define

begin_comment
comment|/* values of TRlldStatus.SelftestStatus */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ST_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_ST_ERROR
value|0x0100
end_define

begin_comment
comment|/* actual errors are 010x, where x is */
end_comment

begin_comment
comment|/* 0: Initial Test Error              */
end_comment

begin_comment
comment|/* 1: Adapter Software Checksum Error */
end_comment

begin_comment
comment|/* 2: Adapter RAM Error               */
end_comment

begin_comment
comment|/* 4: Instruction Test Error          */
end_comment

begin_comment
comment|/* 5: Protocol Handler/RI Hw Error    */
end_comment

begin_comment
comment|/* 6: System Interface Register Error */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ST_TIMEOUT
value|0x0200
end_define

begin_comment
comment|/* The adapter did not complete */
end_comment

begin_comment
comment|/* selftest after download      */
end_comment

begin_comment
comment|/* values of TRlldStatus.Specification.InitStatus */
end_comment

begin_comment
comment|/* the most likely cause of an init error (whatever the code) is a wrong */
end_comment

begin_comment
comment|/* physical or virtual address of the adapter block in TRlldAdapterInit  */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INIT_ERROR
value|0x100
end_define

begin_comment
comment|/* actual errors are 010x, where x is */
end_comment

begin_comment
comment|/* 1: Invalid init block (LLD error)  */
end_comment

begin_comment
comment|/* 2: Invalid options (LLD error)     */
end_comment

begin_comment
comment|/* 3: Invalid rcv burst (LLD error)   */
end_comment

begin_comment
comment|/* 4: Invalid xmt burst (LLD error)   */
end_comment

begin_comment
comment|/* 5: Invalid DMA threshold (LLDerror)*/
end_comment

begin_comment
comment|/* 6: Invalid scb addr                */
end_comment

begin_comment
comment|/* 7: Invalid ssb addr                */
end_comment

begin_comment
comment|/* 8: DIO parity error (HW error)     */
end_comment

begin_comment
comment|/* 9: DMA timeout (May be interrupt                                              failing if PIO mode or PCI2)    */
end_comment

begin_comment
comment|/* A: DMA parity error (HW error)     */
end_comment

begin_comment
comment|/* B: DMA bus error (HW error)        */
end_comment

begin_comment
comment|/* C: DMA data error                  */
end_comment

begin_comment
comment|/* D: Adapter check                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INIT_TIMEOUT
value|0x200
end_define

begin_comment
comment|/* adapter init did not complete      */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INIT_DMA_ERROR
value|0x300
end_define

begin_comment
comment|/* adapter cannot access sys memory   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INIT_INTR_ERROR
value|0x400
end_define

begin_comment
comment|/* adapter cannot interrupt           */
end_comment

begin_define
define|#
directive|define
name|TRLLD_OPEN_TIMEOUT
value|0x500
end_define

begin_comment
comment|/* adapter open did not complete      */
end_comment

begin_comment
comment|/* within 30 seconds                  */
end_comment

begin_define
define|#
directive|define
name|TRLLD_OPEN_ERROR
value|0x600
end_define

begin_comment
comment|/* actual errors are 06xx, where the  */
end_comment

begin_comment
comment|/* bits in x mean:                    */
end_comment

begin_comment
comment|/* 01: Invalid open options (LLDerror)*/
end_comment

begin_comment
comment|/* 04: TxBuffer count error (LLDerror)*/
end_comment

begin_comment
comment|/* 10: Buffer size error (LLD error)  */
end_comment

begin_comment
comment|/* 20: List size error (LLD error)    */
end_comment

begin_comment
comment|/* 40: Node address error             */
end_comment

begin_define
define|#
directive|define
name|TRLLD_OPEN_REPEAT
value|0x700
end_define

begin_comment
comment|/* actual errors are 07xy, where      */
end_comment

begin_comment
comment|/* x is the open phase:               */
end_comment

begin_comment
comment|/* 1: Lobe media test                 */
end_comment

begin_comment
comment|/* 2: Physical Insertion              */
end_comment

begin_comment
comment|/* 3: Address verification            */
end_comment

begin_comment
comment|/* 4: Participation in ring poll      */
end_comment

begin_comment
comment|/* 5: Request Initialization          */
end_comment

begin_comment
comment|/* 9: Request registration (TXI)      */
end_comment

begin_comment
comment|/* A: Lobe Media Test (TXI)           */
end_comment

begin_comment
comment|/* B: Address verification (TXI)      */
end_comment

begin_comment
comment|/* y is the type of error:            */
end_comment

begin_comment
comment|/* 1: Function failure (No Cable ?)   */
end_comment

begin_comment
comment|/* 2: Signal loss                     */
end_comment

begin_comment
comment|/* 5: Timeout                         */
end_comment

begin_comment
comment|/* 6: Ring failure (TKP)              */
end_comment

begin_comment
comment|/* 6: Protocol error (TXI)            */
end_comment

begin_comment
comment|/* 7: Ring beaconing                  */
end_comment

begin_comment
comment|/* 8: Duplicate Node Address (TKP)    */
end_comment

begin_comment
comment|/* 8: Insert Denied (TXI)             */
end_comment

begin_comment
comment|/* 9: Request Initialization (TKP)    */
end_comment

begin_comment
comment|/* 9: Heart beat failure (TXI)        */
end_comment

begin_comment
comment|/* A: Remove received                 */
end_comment

begin_comment
comment|/* B: C-port address changed (TXI)    */
end_comment

begin_comment
comment|/* C: Wire Fault (TKP)                */
end_comment

begin_comment
comment|/* D: Auto Speed, 1. on ring (TKP)    */
end_comment

begin_comment
comment|/* E: Speed sense failed              */
end_comment

begin_comment
comment|/* When opening with FORCE_TXI and only classic token ring attachment is     */
end_comment

begin_comment
comment|/* possible, the error is Request Registration/Timeout or 0x795              */
end_comment

begin_define
define|#
directive|define
name|TRLLD_OPEN_1ST_ON_RING
value|0x800
end_define

begin_comment
comment|/* Speed sense is active, but no other*/
end_comment

begin_comment
comment|/* station is present to set the speed*/
end_comment

begin_comment
comment|/* values of TRlldStatus.Specification.RingStatus */
end_comment

begin_define
define|#
directive|define
name|TRLLD_RS_SIGNAL_LOSS
value|0x8000
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_HARD_ERROR
value|0x4000
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_SOFT_ERROR
value|0x2000
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_TRANSMIT_BEACON
value|0x1000
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_LOBE_WIRE_FAULT
value|0x0800
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_AUTO_REMOVAL_ERROR
value|0x0400
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_REMOVE_RECEIVED
value|0x0100
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_COUNTER_OVERFLOW
value|0x0080
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_SINGLE_STATION
value|0x0040
end_define

begin_define
define|#
directive|define
name|TRLLD_RS_RING_RECOVERY
value|0x0020
end_define

begin_comment
comment|/* values of TRlldStatus.Specification.AdapterCheck */
end_comment

begin_comment
comment|/* MISSING */
end_comment

begin_comment
comment|/* values of TRlldStatus.Specification.PromRemovedCause */
end_comment

begin_define
define|#
directive|define
name|TRLLD_PROM_REMOVE_RECEIVED
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_POLL_FAILURE
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_BUFFER_SIZE
value|3
end_define

begin_comment
comment|/* values of TRlldStatus.Specification.InternalError */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INTERNAL_PIO
value|1
end_define

begin_comment
comment|/* A PIO transfer to or from adapter  */
end_comment

begin_comment
comment|/* did not complete                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INTERNAL_TX
value|2
end_define

begin_comment
comment|/* Trouble with clean up of tx frames */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INTERNAL_RX
value|3
end_define

begin_comment
comment|/* Trouble with clean up of receive   */
end_comment

begin_comment
comment|/* fragments                          */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INTERNAL_CMD
value|4
end_define

begin_comment
comment|/* error response from adapter        */
end_comment

begin_define
define|#
directive|define
name|TRLLD_INTERNAL_STATE
value|5
end_define

begin_comment
comment|/* event happened in unexpected state */
end_comment

begin_comment
comment|/* values of TRlldStatus.Specification.AdapterTimeout */
end_comment

begin_define
define|#
directive|define
name|TRLLD_COMMAND_TIMEOUT
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_TIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_INTERRUPT_TIMEOUT
value|3
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* TRlldStatistics contains the adapter statistics returned to Driver        */
end_comment

begin_comment
comment|/* in TRlldStatistics calls and DriverStatistics call-backs                  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|TRlldStatistics
block|{
name|unsigned
name|long
name|LineErrors
decl_stmt|;
name|unsigned
name|long
name|InternalErrors
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|BurstErrors
decl_stmt|;
name|unsigned
name|long
name|ARIFCIErrors
decl_stmt|;
name|unsigned
name|long
name|AbortDelimiters
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|LostFrames
decl_stmt|;
name|unsigned
name|long
name|CongestionErrors
decl_stmt|;
name|unsigned
name|long
name|FrameCopiedErrors
decl_stmt|;
name|unsigned
name|long
name|FrequencyErrors
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|TokenErrors
decl_stmt|;
name|unsigned
name|long
name|DMABusErrors
decl_stmt|;
comment|/* Not maintained by 3139 */
name|unsigned
name|long
name|DMAParityErrors
decl_stmt|;
comment|/* Not maintained by 3139 */
name|unsigned
name|long
name|ReceiveLongFrame
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|ReceiveCRCErrors
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|ReceiveOverflow
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|TransmitUnderrun
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|UnderrunLock
decl_stmt|;
comment|/* Not maintained by TMS based boards */
name|unsigned
name|long
name|OverflowReset
decl_stmt|;
name|unsigned
name|char
name|UpstreamNeighbour
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|RingNumber
decl_stmt|;
name|unsigned
name|char
name|BeaconingUpstreamNeighbour
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|short
name|padding
decl_stmt|;
block|}
name|TRlldStatistics_t
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* TRlldDriver contains the Driver call-backs                                */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|TRlldDriver
block|{
name|unsigned
name|long
name|TRlldVersion
decl_stmt|;
ifndef|#
directive|ifndef
name|TRlldInlineIO
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverOutByte
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|unsigned
name|char
name|Value
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverOutWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|unsigned
name|short
name|Value
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverOutDWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|unsigned
name|long
name|Value
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepOutByte
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|ByteCount
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepOutWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldWordDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|WordCount
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepOutDWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldDWordDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|DWordCount
parameter_list|)
function_decl|;
name|unsigned
name|char
function_decl|(
name|CDECL
modifier|*
name|DriverInByte
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|)
function_decl|;
name|unsigned
name|short
function_decl|(
name|CDECL
modifier|*
name|DriverInWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|)
function_decl|;
name|unsigned
name|long
function_decl|(
name|CDECL
modifier|*
name|DriverInDWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepInByte
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|ByteCount
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepInWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldWordDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|WordCount
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRepInDWord
function_decl|)
parameter_list|(
name|unsigned
name|short
name|IOAddress
parameter_list|,
name|TRlldDWordDataPtr_t
name|DataPointer
parameter_list|,
name|int
name|DWordCount
parameter_list|)
function_decl|;
endif|#
directive|endif
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverSuspend
function_decl|)
parameter_list|(
name|unsigned
name|short
name|MicroSeconds
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverStatus
function_decl|)
parameter_list|(
name|void
modifier|*
name|DriverHandle
parameter_list|,
name|TRlldStatus_t
modifier|*
name|Status
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverCloseCmpltd
function_decl|)
parameter_list|(
name|void
modifier|*
name|DriverHandle
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverStatistics
function_decl|)
parameter_list|(
name|void
modifier|*
name|DriverHandle
parameter_list|,
name|TRlldStatistics_t
modifier|*
name|Statistics
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverTxFrameCmpltd
function_decl|)
parameter_list|(
name|void
modifier|*
name|DriverHandle
parameter_list|,
name|void
modifier|*
name|FrameHandle
parameter_list|,
name|int
name|TxStatus
parameter_list|)
function_decl|;
name|void
function_decl|(
name|CDECL
modifier|*
name|DriverRcvFrameCmpltd
function_decl|)
parameter_list|(
name|void
modifier|*
name|DriverHandle
parameter_list|,
name|int
name|ByteCount
parameter_list|,
name|int
name|FragmentCount
parameter_list|,
name|void
modifier|*
name|FragmentHandle
parameter_list|,
name|int
name|RcvStatus
parameter_list|)
function_decl|;
block|}
name|TRlldDriver_t
typedef|;
end_typedef

begin_comment
comment|/* Version and model control */
end_comment

begin_define
define|#
directive|define
name|TRLLD_VERSION_INLINEIO
value|0x8000
end_define

begin_define
define|#
directive|define
name|TRLLD_VERSION_SMALL
value|0x4000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TRlldInlineIO
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TRlldSmall
end_ifdef

begin_define
define|#
directive|define
name|TRLLD_VERSION
value|0x4120
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRLLD_VERSION
value|0x0120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|TRlldSmall
end_ifdef

begin_define
define|#
directive|define
name|TRLLD_VERSION
value|0xC120
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRLLD_VERSION
value|0x8120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* TRlldAdapterConfig contains the properties found for an adapter           */
end_comment

begin_comment
comment|/* used when finding and defining adapters to use                            */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_struct
struct|struct
name|pnp_id
block|{
name|unsigned
name|short
name|vendor
decl_stmt|;
name|unsigned
name|short
name|device
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_id
block|{
name|unsigned
name|short
name|vendor
decl_stmt|;
name|unsigned
name|short
name|device
decl_stmt|;
name|unsigned
name|char
name|revision
decl_stmt|;
name|unsigned
name|char
name|reserved_byte
decl_stmt|;
name|unsigned
name|short
name|reserved_word
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcmcia_id
block|{
comment|/* unknown as yet */
name|unsigned
name|char
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pci_slot
block|{
name|unsigned
name|short
name|bus_no
decl_stmt|;
name|unsigned
name|short
name|device_no
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcmcia_socket
block|{
comment|/* unknown as yet */
name|unsigned
name|char
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|TRlldAdapterConfig
block|{
name|unsigned
name|char
name|type
decl_stmt|;
name|unsigned
name|char
name|bus
decl_stmt|;
name|unsigned
name|short
name|magic
decl_stmt|;
union|union
block|{
name|struct
name|pnp_id
name|pnp
decl_stmt|;
name|unsigned
name|long
name|eisa
decl_stmt|;
name|unsigned
name|short
name|mca
decl_stmt|;
name|struct
name|pci_id
name|pci
decl_stmt|;
name|struct
name|pcmcia_id
name|pcmcia
decl_stmt|;
block|}
name|id
union|;
union|union
block|{
name|unsigned
name|short
name|csn
decl_stmt|;
name|unsigned
name|short
name|eisa
decl_stmt|;
name|unsigned
name|short
name|mca
decl_stmt|;
name|struct
name|pci_slot
name|pci
decl_stmt|;
name|struct
name|pcmcia_socket
name|pcmcia
decl_stmt|;
block|}
name|slot
union|;
name|unsigned
name|short
name|iobase0
decl_stmt|;
name|unsigned
name|short
name|iolength0
decl_stmt|;
name|unsigned
name|short
name|iobase1
decl_stmt|;
name|unsigned
name|short
name|iolength1
decl_stmt|;
name|unsigned
name|long
name|memorybase
decl_stmt|;
name|unsigned
name|short
name|memorylength
decl_stmt|;
name|unsigned
name|char
name|mode
decl_stmt|;
name|unsigned
name|char
name|xmode
decl_stmt|;
name|unsigned
name|char
name|interruptlevel
decl_stmt|;
name|unsigned
name|char
name|dmalevel
decl_stmt|;
name|unsigned
name|char
name|macaddress
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|long
name|prombase
decl_stmt|;
name|unsigned
name|char
name|speed
decl_stmt|;
name|unsigned
name|char
name|cachelinesize
decl_stmt|;
name|unsigned
name|short
name|pcicommand
decl_stmt|;
name|unsigned
name|char
name|mactype
decl_stmt|;
name|unsigned
name|char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|TRlldAdapterConfig_t
typedef|;
end_typedef

begin_comment
comment|/* values of TRlldAdapterConfig.Type */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_XT
value|0
end_define

begin_comment
comment|/* not supported             */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_ISA1
value|1
end_define

begin_comment
comment|/* OC-3115                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_ISA2
value|2
end_define

begin_comment
comment|/* OC-3117                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_ISA3
value|3
end_define

begin_comment
comment|/* OC-3118                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_MCA1
value|4
end_define

begin_comment
comment|/* OC-3129 id A84            */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_MCA2
value|5
end_define

begin_comment
comment|/* OC-3129 id A85            */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_MCA3
value|6
end_define

begin_comment
comment|/* OC-3129 id A86            */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_EISA1
value|7
end_define

begin_comment
comment|/* OC-3133 id 0109833D       */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_EISA2
value|8
end_define

begin_comment
comment|/* OC-3133 id 0209833D       */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_EISA3
value|9
end_define

begin_comment
comment|/* OC-3135 not supported     */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI1
value|10
end_define

begin_comment
comment|/* OC-3136 id 108d0001 rev 1 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI2
value|11
end_define

begin_comment
comment|/* OC-3136 id 108d0001 rev 2 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI3
value|12
end_define

begin_comment
comment|/* OC-3137 id 108d0001 rev 3 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI4
value|13
end_define

begin_comment
comment|/* OC-3139 id 108d0004 rev 2 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI5
value|14
end_define

begin_comment
comment|/* OC-3140 id 108d0004 rev 3 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI6
value|15
end_define

begin_comment
comment|/* OC-3141 id 108d0007 rev 1 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI7
value|19
end_define

begin_comment
comment|/* OC-3540 id 108d0008 rev 1 */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCI8
value|20
end_define

begin_comment
comment|/* OC-3150 id 108d000a rev 1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCMCIA
end_ifdef

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCCARD1
value|16
end_define

begin_comment
comment|/* OC-3220                   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCCARD2
value|17
end_define

begin_comment
comment|/* OC-3221,OC-3230,OC-3232   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRLLD_ADAPTER_PCCARD3
value|18
end_define

begin_comment
comment|/* OC-3250 id 108d0005 rev 1 */
end_comment

begin_comment
comment|/* values of TRlldAdapterConfig.Bus */
end_comment

begin_define
define|#
directive|define
name|TRLLD_BUS_ISA
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_BUS_EISA
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_BUS_MCA
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_BUS_PCI
value|4
end_define

begin_define
define|#
directive|define
name|TRLLD_BUS_PCMCIA
value|5
end_define

begin_comment
comment|/* values of TRlldAdapterConfig.mode */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_16M
value|0x01
end_define

begin_comment
comment|/* needs data buffers below 16 M     */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_PHYSICAL
value|0x02
end_define

begin_comment
comment|/* needs valid physical addresses    */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_FIXED_CFG
value|0x04
end_define

begin_comment
comment|/* cannot be reconfigured            */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_SHORT_SLOT
value|0x08
end_define

begin_comment
comment|/* in short ISA slot, cannot use DMA */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_CANNOT_DISABLE
value|0x10
end_define

begin_comment
comment|/* can not disable interrupt         */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_SHARE_INTERRUPT
value|0x20
end_define

begin_comment
comment|/* may share interrupt               */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MODE_MEMORY
value|0x40
end_define

begin_comment
comment|/* is configured with a memory window*/
end_comment

begin_comment
comment|/* values of TRlldAdapterConfig.dma */
end_comment

begin_define
define|#
directive|define
name|TRLLD_DMA_PIO
value|4
end_define

begin_comment
comment|/* other values signifies the DMA channel */
end_comment

begin_define
define|#
directive|define
name|TRLLD_DMA_MASTER
value|0xff
end_define

begin_comment
comment|/* to use                                 */
end_comment

begin_comment
comment|/* values of TRlldAdapterConfig.mactype */
end_comment

begin_comment
comment|/* download with:   */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MAC_TMS
value|1
end_define

begin_comment
comment|/* TRlldMACCode     */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MAC_HAWKEYE
value|2
end_define

begin_comment
comment|/* TRlldHawkeyeMAC  */
end_comment

begin_define
define|#
directive|define
name|TRLLD_MAC_BULLSEYE
value|3
end_define

begin_comment
comment|/* TRlldBullseyeMAC */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|TRlldAdapter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|TRlldAdapterType_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_FRAGMENTS
end_ifndef

begin_define
define|#
directive|define
name|MAX_FRAGMENTS
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|TRlldTransmit
block|{
name|unsigned
name|short
name|FragmentCount
decl_stmt|;
name|unsigned
name|short
name|TRlldTransmitReserved
decl_stmt|;
struct|struct
name|TRlldTransmitFragment
block|{
name|unsigned
name|long
name|PhysicalAddress
decl_stmt|;
name|TRlldDataPtr_t
name|VirtualAddress
decl_stmt|;
name|unsigned
name|short
name|count
decl_stmt|;
name|unsigned
name|short
name|TRlldTransmitFragmentReserved
decl_stmt|;
block|}
name|TransmitFragment
index|[
name|MAX_FRAGMENTS
index|]
struct|;
block|}
name|TRlldTransmit_t
typedef|;
end_typedef

begin_function_decl
name|int
name|CDECL
name|TRlldAdapterSize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldInit
parameter_list|(
name|int
name|TypeCount
parameter_list|,
name|TRlldAdapterType_t
modifier|*
name|AdapterTypeTable
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3115
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ISA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3117
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3118
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3129
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MCA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3133
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EISA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3136
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCI adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3137
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3139
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hawkeye adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3540
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bullseye adapters */
end_comment

begin_define
define|#
directive|define
name|T3115
value|&TRlld3115
end_define

begin_define
define|#
directive|define
name|T3117
value|&TRlld3117
end_define

begin_define
define|#
directive|define
name|T3118
value|&TRlld3118
end_define

begin_define
define|#
directive|define
name|T3129
value|&TRlld3129
end_define

begin_define
define|#
directive|define
name|T3133
value|&TRlld3133
end_define

begin_define
define|#
directive|define
name|T3136
value|&TRlld3136
end_define

begin_define
define|#
directive|define
name|T3137
value|&TRlld3137
end_define

begin_define
define|#
directive|define
name|T3139
value|&TRlld3139
end_define

begin_define
define|#
directive|define
name|T3540
value|&TRlld3540
end_define

begin_comment
comment|/* Only for Boot Prom Page Zero code */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3115Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ISA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3117Boot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3118Boot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3129Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MCA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3133Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EISA adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3136Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PCI adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3137Boot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3139Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hawkeye adapters */
end_comment

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3150Boot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3250Boot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TRlldAdapterType_t
name|CDECL
name|TRlld3540Boot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Bullseye adapter */
end_comment

begin_define
define|#
directive|define
name|B3115
value|&TRlld3115Boot
end_define

begin_define
define|#
directive|define
name|B3117
value|&TRlld3117Boot
end_define

begin_define
define|#
directive|define
name|B3118
value|&TRlld3118Boot
end_define

begin_define
define|#
directive|define
name|B3129
value|&TRlld3129Boot
end_define

begin_define
define|#
directive|define
name|B3133
value|&TRlld3133Boot
end_define

begin_define
define|#
directive|define
name|B3136
value|&TRlld3136Boot
end_define

begin_define
define|#
directive|define
name|B3137
value|&TRlld3137Boot
end_define

begin_define
define|#
directive|define
name|B3139
value|&TRlld3139Boot
end_define

begin_define
define|#
directive|define
name|B3150
value|&TRlld3150Boot
end_define

begin_define
define|#
directive|define
name|B3250
value|&TRlld3250Boot
end_define

begin_define
define|#
directive|define
name|B3540
value|&TRlld3540Boot
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_UNKNOWN
value|5
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldAdapterInit
parameter_list|(
name|TRlldDriver_t
modifier|*
name|DriverDefinition
parameter_list|,
name|TRlldAdapter_t
modifier|*
name|TRlldAdapter
parameter_list|,
name|unsigned
name|long
name|TRlldAdapterPhysical
parameter_list|,
name|void
modifier|*
name|DriverHandle
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_INIT_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_NOT_FOUND
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_UNSUPPORTED
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_PHYS16
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_INIT_VERSION
value|4
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldSetSpeed
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|char
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_SPEED_4MBPS
value|4
end_define

begin_define
define|#
directive|define
name|TRLLD_SPEED_16MBPS
value|16
end_define

begin_define
define|#
directive|define
name|TRLLD_SPEED_100MBPS
value|100
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldSetInterrupt
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|char
name|interruptlevel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldSetDMA
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|char
name|dma
parameter_list|,
name|unsigned
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_CONFIG_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_CONFIG_STATE
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_CONFIG_ILLEGAL
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_CONFIG_FAILED
value|3
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldSetSpecial
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|short
name|param1
parameter_list|,
name|unsigned
name|short
name|param2
parameter_list|,
name|unsigned
name|short
name|param3
parameter_list|,
name|unsigned
name|short
name|param4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldAddMemory
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldDataPtr_t
name|virtual
parameter_list|,
name|unsigned
name|long
name|physical
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldDisable
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_NOT_SUPPORTED
value|1
end_define

begin_function_decl
name|void
name|CDECL
name|TRlldEnable
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldInterruptPresent
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_NO_INTERRUPT
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_INTERRUPT
value|1
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldInterruptService
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldInterruptPreService
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CDECL
name|TRlldInterruptPostService
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldPoll
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldDownload
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|char
modifier|*
name|DownLoadCode
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_DOWNLOAD_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_DOWNLOAD_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_STATE
value|2
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
name|CDECL
modifier|*
name|GetCode_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|unsigned
name|char
modifier|*
name|maccodebyte
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|CDECL
name|TRlldStreamDownload
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|GetCode_t
name|procedure
parameter_list|,
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldOpen
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|char
modifier|*
name|MACAddress
parameter_list|,
name|unsigned
name|long
name|GroupAddress
parameter_list|,
name|unsigned
name|long
name|FunctionalAddress
parameter_list|,
name|unsigned
name|short
name|MaxFrameSize
parameter_list|,
name|unsigned
name|short
name|OpenModes
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_OPEN_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_OPEN_STATE
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_OPEN_ADDRESS_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_OPEN_MODE_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_OPEN_MEMORY
value|4
end_define

begin_define
define|#
directive|define
name|TRLLD_MODE_TX_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|TRLLD_MODE_RX_SINGLE
value|0x02
end_define

begin_define
define|#
directive|define
name|TRLLD_MODE_FORCE_TKP
value|0x04
end_define

begin_define
define|#
directive|define
name|TRLLD_MODE_FORCE_TXI
value|0x08
end_define

begin_define
define|#
directive|define
name|TRLLD_MODE_TX_CRC
value|0x10
end_define

begin_function_decl
name|void
name|CDECL
name|TRlldClose
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|int
name|immediate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CDECL
name|TRlldSetGroupAddress
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|long
name|GroupAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CDECL
name|TRlldSetFunctionalAddress
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|long
name|FunctionalAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CDECL
name|TRlldSetPromiscuousMode
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|unsigned
name|char
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mode bits */
end_comment

begin_define
define|#
directive|define
name|TRLLD_PROM_LLC
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_MAC
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_ERRORFRAMES
value|4
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldGetStatistics
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldStatistics_t
modifier|*
name|statistics
parameter_list|,
name|int
name|immediate
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_IMMEDIATE_STATISTICS
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_STATISTICS_RETRIEVED
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_STATISTICS_PENDING
value|1
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldTransmitFrame
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldTransmit_t
modifier|*
name|TransmitFrame
parameter_list|,
name|void
modifier|*
name|FrameHandle
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_NOT_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_TOO_MANY
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_MAX16
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|TRLLD_TRANSMIT_EMPTY
value|5
end_define

begin_comment
comment|/* completion flags */
end_comment

begin_define
define|#
directive|define
name|TRLLD_TX_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_TX_NOT_PROCESSED
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_TX_NOT_RECOGNIZED
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_TX_NOT_COPIED
value|3
end_define

begin_comment
comment|/* number of free transmit fragments */
end_comment

begin_function_decl
name|int
name|CDECL
name|TRlldTransmitFree
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldReceiveFragment
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldDataPtr_t
name|FragmentStart
parameter_list|,
name|unsigned
name|long
name|FragmentPhysical
parameter_list|,
name|int
name|count
parameter_list|,
name|void
modifier|*
name|FragmentHandle
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_RECEIVE_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_RECEIVE_NOT_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_RECEIVE_TOO_MANY
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_RECEIVE_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_RECEIVE_MAX16
value|4
end_define

begin_comment
comment|/* completion flags */
end_comment

begin_define
define|#
directive|define
name|TRLLD_RCV_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_RCV_NO_DATA
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_RCV_ERROR
value|2
end_define

begin_comment
comment|/* Only when TRLLD_PROM_ERRORFRAMES */
end_comment

begin_define
define|#
directive|define
name|TRLLD_RCV_LONG
value|3
end_define

begin_comment
comment|/* number of free receive fragments */
end_comment

begin_function_decl
name|int
name|CDECL
name|TRlldReceiveFree
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldFind
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config_table
parameter_list|,
name|unsigned
name|long
name|type_mask
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* type mask bits */
end_comment

begin_define
define|#
directive|define
name|OC_3115
value|0x0001
end_define

begin_define
define|#
directive|define
name|OC_3117
value|0x0002
end_define

begin_define
define|#
directive|define
name|OC_3118
value|0x0004
end_define

begin_define
define|#
directive|define
name|OC_3129
value|0x0008
end_define

begin_define
define|#
directive|define
name|OC_3133
value|0x0010
end_define

begin_define
define|#
directive|define
name|OC_3136
value|0x0040
end_define

begin_define
define|#
directive|define
name|OC_3137
value|0x0080
end_define

begin_define
define|#
directive|define
name|OC_3139
value|0x0100
end_define

begin_define
define|#
directive|define
name|OC_3140
value|0x0200
end_define

begin_define
define|#
directive|define
name|OC_3141
value|0x0400
end_define

begin_define
define|#
directive|define
name|OC_3540
value|0x0800
end_define

begin_define
define|#
directive|define
name|OC_3150
value|0x1000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PCMCIA
end_ifdef

begin_define
define|#
directive|define
name|OC_3220
value|0x0800
end_define

begin_define
define|#
directive|define
name|OC_3221
value|0x1000
end_define

begin_define
define|#
directive|define
name|OC_3230
value|0x2000
end_define

begin_define
define|#
directive|define
name|OC_3232
value|0x4000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OC_3250
value|0x8000
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldIOAddressConfig
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|,
name|unsigned
name|short
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_FIND_OK
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_FIND_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_FIND_VERSION
value|-1
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldEISASlotConfig
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldMCASlotConfig
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldPCIConfig
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|,
name|char
modifier|*
name|PCIConfigurationSpace
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PCICONFIG_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PCICONFIG_FAIL
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PCICONFIG_SET_COMMAND
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_PCICONFIG_VERSION
value|3
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldFindPCI
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config_table
parameter_list|,
name|unsigned
name|long
name|type_mask
parameter_list|,
name|int
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PCMCIA
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|PCCardHandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|CDECL
modifier|*
name|GetTupleData_t
function_decl|)
parameter_list|(
name|PCCardHandle_t
name|handle
parameter_list|,
name|unsigned
name|short
name|TupleIdent
parameter_list|,
name|char
modifier|*
name|TupleData
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|CDECL
name|TRlldPCCardConfig
parameter_list|(
name|TRlldDriver_t
modifier|*
name|driver
parameter_list|,
name|TRlldAdapterConfig_t
modifier|*
name|config
parameter_list|,
name|unsigned
name|short
name|address
parameter_list|,
name|int
name|irq
parameter_list|,
name|GetTupleData_t
name|GetTuple
parameter_list|,
name|PCCardHandle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PCCARD_CONFIG_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PCCARD_CONFIG_FAIL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Boot Prom Support */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|TRlldPromInfo
block|{
name|unsigned
name|short
name|PromIdent
decl_stmt|;
name|short
name|PromPages
decl_stmt|;
name|short
name|PromPageSize
decl_stmt|;
block|}
name|TRlldPromInfo_t
typedef|;
end_typedef

begin_function_decl
name|int
name|CDECL
name|TRlldMapBootProm
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldDataPtr_t
name|prompointer
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PROM_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_FAILED
value|3
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldGetPromInfo
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|TRlldPromInfo_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PROM_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MOUNTED
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MAPPED
value|2
end_define

begin_function_decl
name|void
name|CDECL
name|TRlldSetPromPage
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|int
name|page
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CDECL
name|TRlldSetMemoryUse
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|int
name|use
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PROM_TO_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_REGISTERS_TO_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_MEMORY_USE_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_MEMORY_USE_NO_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_MEMORY_USE_STATE
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_MEMORY_USE_ILLEGAL
value|3
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldPromErase
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|void
function_decl|(
name|CDECL
modifier|*
name|delay
function_decl|)
parameter_list|(
name|int
name|milliseconds
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PROM_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MOUNTED
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MAPPED
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_FAILED
value|3
end_define

begin_function_decl
name|int
name|CDECL
name|TRlldPromWrite
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TRLLD_PROM_OK
value|0
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MOUNTED
value|1
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_NOT_MAPPED
value|2
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_FAILED
value|3
end_define

begin_define
define|#
directive|define
name|TRLLD_PROM_ILLEGAL
value|4
end_define

begin_function_decl
name|void
name|CDECL
name|TRlldEmergency
parameter_list|(
name|TRlldAdapter_t
modifier|*
name|adapter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert from TRlldAdapterConfig.type to name string */
end_comment

begin_function_decl
name|char
modifier|*
name|CDECL
name|TRlldAdapterName
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

