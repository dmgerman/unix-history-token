begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      enet.h	Stanford	25 April 1983 */
end_comment

begin_comment
comment|/*  *  Ethernet definitions needed for user processes  *  **********************************************************************  * HISTORY  * 7 October 1985	Jeff Mogul	Stanford  *	Added EIOCMFREE ioctl to indicate # of free minor devices;  *	may or may not be useful.  * 17 October 1984	Jeff Mogul	Stanford  *	Added ENF_CAND, ENF_COR, ENF_CNAND, and ENF_CNOR, short-circuit  *	operators, to make filters run faster.  *	All evaluate "(*sp++ == *sp++)":  *	ENF_CAND: returns false immediately if result is false, otherwise  *		continue  *	ENF_COR: returns true immediately if result is true, otherwise  *		continue  *	ENF_CNAND: returns true immediately if result is false, otherwise  *		continue  *	ENF_CNOR: returns false immediately if result is true, otherwise  *		continue  *	Also added ENF_NEQ to complement ENF_EQ  *  * 10 November 1983	Jeffrey Mogul	Stanford  *	Slight restructuring for support of 10mb ethers;  *	added the EIOCDEVP ioctl and associated definitions  *	and removed the EIOCMTU ioctl (subsumed by EIOCDEVP)  *  * 25-Apr-83	Jeffrey Mogul	Stanford  *	Began conversion to 4.2BSD.  This involves removing all  *	references to the actual hardware.  *	Incompatible change: ioctl encodings!  *	Added EIOCMTU ioctl to get MTU (max packet size).  *	Most previous history comments removed.  *	Definitions of interest only to kernel now are in enetdefs.h  *  * 10-Aug-82  Mike Accetta (mja) at Carnegie-Mellon University  *	Added EIOCMBIS and EIOCMBIC definitions, and new ENHOLDSIG mode  *	bit and ENPRIVMODES defintions (V3.05e). [Last change before  *	4.2BSD conversion starts.]  *  * 22-Feb-80  Rick Rashid (rfr) at Carnegie-Mellon University  *	Rewritten for multiple simultaneous opens with filters (V1.05).  *  * 18-Jan-80  Mike Accetta (mja) at Carnegie-Mellon University  *      Created (V1.00).  *  **********************************************************************  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_define
define|#
directive|define
name|ENMAXFILTERS
value|40
end_define

begin_comment
comment|/* maximum filter short words */
end_comment

begin_comment
comment|/*  *  filter structure for SETF  */
end_comment

begin_struct
struct|struct
name|enfilter
block|{
name|u_char
name|enf_Priority
decl_stmt|;
comment|/* priority of filter */
name|u_char
name|enf_FilterLen
decl_stmt|;
comment|/* length of filter command list */
name|u_short
name|enf_Filter
index|[
name|ENMAXFILTERS
index|]
decl_stmt|;
comment|/* the filter command list */
block|}
struct|;
end_struct

begin_comment
comment|/*  set/get parameters, set filter ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|EIOCSETP
value|_IOW(E,100, struct eniocb)
end_define

begin_define
define|#
directive|define
name|EIOCGETP
value|_IOR(E,101, struct eniocb)
end_define

begin_define
define|#
directive|define
name|EIOCSETF
value|_IOW(E,102, struct enfilter)
end_define

begin_define
define|#
directive|define
name|EIOCENBS
value|_IOW(E,103, int)
end_define

begin_define
define|#
directive|define
name|EIOCINHS
value|_IO(E,104)
end_define

begin_define
define|#
directive|define
name|EIOCSETW
value|_IOW(E,105, u_int)
end_define

begin_define
define|#
directive|define
name|EIOCFLUSH
value|_IO(E,106)
end_define

begin_define
define|#
directive|define
name|EIOCALLOCP
value|_IO(E,107)
end_define

begin_define
define|#
directive|define
name|EIOCDEALLOCP
value|_IO(E,108)
end_define

begin_define
define|#
directive|define
name|EIOCMBIS
value|_IOW(E,109, u_short)
end_define

begin_define
define|#
directive|define
name|EIOCMBIC
value|_IOW(E,110, u_short)
end_define

begin_define
define|#
directive|define
name|EIOCDEVP
value|_IOR(E,111, struct endevp)
end_define

begin_define
define|#
directive|define
name|EIOCMFREE
value|_IOR(E,112, int)
end_define

begin_comment
comment|/*  *  Bits in mode word modified by EIOCMBIS and EIOCMBIC.  */
end_comment

begin_define
define|#
directive|define
name|ENHOLDSIG
value|(0x0001)
end_define

begin_comment
comment|/* don't disable signal after sending */
end_comment

begin_define
define|#
directive|define
name|ENPRIVMODES
value|(~(ENHOLDSIG))
end_define

begin_comment
comment|/*  *  We now allow specification of up to MAXFILTERS (short) words of a filter  *  command list to be applied to incoming packets to determine if  *  those packets should be given to a particular open ethernet file.  *    *  Each open enet file specifies the filter command list via iocontrl.  *  Each filter command list specifies a sequences of actions which leave a  *  boolean value on the top of an internal stack.  Each word of the  *  command list specifies an action from the set {PUSHLIT, PUSHZERO,  *  PUSHWORD+N} which respectively push the next word of the stack, zero,  *  or word N of the incoming packet on the stack, and a binary operator  *  from the set {EQ, LT, LE, GT, GE, AND, OR, XOR} which operates on the  *  top two elements of the stack and replaces them with its result.  The  *  special action NOPUSH and the special operator NOP can be used to only  *  perform the binary operation or to only push a value on the stack.  *    *  If the final value of the filter operation is true, then the packet is  *  accepted for the open file which specified the filter.  *    */
end_comment

begin_comment
comment|/*  these must sum to 16!  */
end_comment

begin_define
define|#
directive|define
name|ENF_NBPA
value|10
end_define

begin_comment
comment|/* # bits / action */
end_comment

begin_define
define|#
directive|define
name|ENF_NBPO
value|6
end_define

begin_comment
comment|/* # bits / operator */
end_comment

begin_comment
comment|/*  binary operators  */
end_comment

begin_define
define|#
directive|define
name|ENF_NOP
value|(0<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_EQ
value|(1<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_LT
value|(2<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_LE
value|(3<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_GT
value|(4<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_GE
value|(5<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_AND
value|(6<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_OR
value|(7<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_XOR
value|(8<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_COR
value|(9<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_CAND
value|(10<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_CNOR
value|(11<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_CNAND
value|(12<<ENF_NBPA)
end_define

begin_define
define|#
directive|define
name|ENF_NEQ
value|(13<<ENF_NBPA)
end_define

begin_comment
comment|/*  stack actions  */
end_comment

begin_define
define|#
directive|define
name|ENF_NOPUSH
value|0
end_define

begin_define
define|#
directive|define
name|ENF_PUSHLIT
value|1
end_define

begin_define
define|#
directive|define
name|ENF_PUSHZERO
value|2
end_define

begin_define
define|#
directive|define
name|ENF_PUSHWORD
value|16
end_define

begin_comment
comment|/*  *  parameter buffer structure for GETP and SETP  */
end_comment

begin_struct
struct|struct
name|eniocb
block|{
name|u_char
name|en_addr
decl_stmt|;
comment|/* ethernet address (RO) */
name|u_char
name|en_maxfilters
decl_stmt|;
comment|/* max filter words available (RO) */
name|u_char
name|en_maxwaiting
decl_stmt|;
comment|/* max queued input packets (RO) */
name|u_char
name|en_maxpriority
decl_stmt|;
comment|/* max filter priority for this file (RO) */
name|long
name|en_rtout
decl_stmt|;
comment|/* receive timeout in (jiffies) (RW) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * parameter structure for EIOCDEVP (get device parameters)  */
end_comment

begin_define
define|#
directive|define
name|EN_MAX_ADDR_LEN
value|8
end_define

begin_comment
comment|/* maximum bytes in a hardware address */
end_comment

begin_struct
struct|struct
name|endevp
block|{
name|u_char
name|end_dev_type
decl_stmt|;
comment|/* device type, codes below */
name|u_char
name|end_addr_len
decl_stmt|;
comment|/* length (bytes) of a hardware address */
name|u_short
name|end_hdr_len
decl_stmt|;
comment|/* length of a hardware packet header */
name|u_short
name|end_MTU
decl_stmt|;
comment|/* maximum packet size (bytes) */
name|u_char
name|end_addr
index|[
name|EN_MAX_ADDR_LEN
index|]
decl_stmt|;
comment|/* hardware address for this unit */
name|u_char
name|end_broadaddr
index|[
name|EN_MAX_ADDR_LEN
index|]
decl_stmt|;
comment|/* hardware-supported broadcast address */
block|}
struct|;
end_struct

begin_comment
comment|/* Ethernet Device Type codes */
end_comment

begin_define
define|#
directive|define
name|ENDT_3MB
value|3
end_define

begin_comment
comment|/* Xerox Experimental Ethernet */
end_comment

begin_define
define|#
directive|define
name|ENDT_BS3MB
value|1
end_define

begin_comment
comment|/* Xerox Experimental Ethernet/byteswapped */
end_comment

begin_define
define|#
directive|define
name|ENDT_10MB
value|2
end_define

begin_comment
comment|/* Xerox-DEC-Intel Standard Ethernet */
end_comment

begin_define
define|#
directive|define
name|ENDT_MIN
value|1
end_define

begin_comment
comment|/* minimum defined device type code */
end_comment

begin_define
define|#
directive|define
name|ENDT_MAX
value|3
end_define

begin_comment
comment|/* maximum defined device type code */
end_comment

end_unit

