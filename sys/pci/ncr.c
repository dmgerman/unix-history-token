begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** **  $Id: ncr.c,v 1.15 1995/02/02 12:36:16 davidg Exp $ ** **  Device driver for the   NCR 53C810   PCI-SCSI-Controller. ** **  386bsd / FreeBSD / NetBSD ** **------------------------------------------------------------------------- ** **  Written for 386bsd and FreeBSD by **	Wolfgang Stanglmeier<wolf@dentaro.gun.de> **	Stefan Esser<se@mi.Uni-Koeln.de> ** **  Ported to NetBSD by **	Charles M. Hannum<mycroft@gnu.ai.mit.edu> ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
end_comment

begin_define
define|#
directive|define
name|NCR_PATCHLEVEL
value|"pl4 95/01/27"
end_define

begin_define
define|#
directive|define
name|NCR_VERSION
value|(2)
end_define

begin_define
define|#
directive|define
name|MAX_UNITS
value|(16)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LDSC
end_ifndef

begin_comment
comment|/* belongs to sstat2 in ncrreg.h */
end_comment

begin_define
define|#
directive|define
name|LDSC
value|0x02
end_define

begin_comment
comment|/* sta: disconnect& reconnect      */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	Configuration and Debugging ** **	May be overwritten in<arch/conf/XXXXX> ** **========================================================== */
end_comment

begin_comment
comment|/* **    SCSI address of this device. **    The boot routines should have set it. **    If not, use this. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_NCR_MYADDR
end_ifndef

begin_define
define|#
directive|define
name|SCSI_NCR_MYADDR
value|(7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_NCR_MYADDR */
end_comment

begin_comment
comment|/* **    The maximal synchronous frequency in kHz. **    (0=asynchronous) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_NCR_MAX_SYNC
end_ifndef

begin_define
define|#
directive|define
name|SCSI_NCR_MAX_SYNC
value|(10000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_NCR_MAX_SYNC */
end_comment

begin_comment
comment|/* **    The maximal bus with (in log2 byte) **    (0=8 bit, 1=16 bit) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_NCR_MAX_WIDE
end_ifndef

begin_define
define|#
directive|define
name|SCSI_NCR_MAX_WIDE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_NCR_MAX_WIDE */
end_comment

begin_comment
comment|/* **    The maximum number of tags per logic unit. **    Used only for disk devices that support tags. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_NCR_MAX_TAGS
end_ifndef

begin_define
define|#
directive|define
name|SCSI_NCR_MAX_TAGS
value|(4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_NCR_MAX_TAGS */
end_comment

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Configuration and Debugging ** **========================================================== */
end_comment

begin_comment
comment|/* **    Number of targets supported by the driver. **    n permits target numbers 0..n-1. **    Default is 7, meaning targets #0..#6. **    #7 .. is myself. */
end_comment

begin_define
define|#
directive|define
name|MAX_TARGET
value|(7)
end_define

begin_comment
comment|/* **    Number of logic units supported by the driver. **    n enables logic unit numbers 0..n-1. **    The common SCSI devices require only **    one lun, so take 1 as the default. */
end_comment

begin_define
define|#
directive|define
name|MAX_LUN
value|(1)
end_define

begin_comment
comment|/* **    The maximum number of jobs scheduled for starting. **    There should be one slot per target, and one slot **    for each tag of each target. */
end_comment

begin_define
define|#
directive|define
name|MAX_START
value|(7 * SCSI_NCR_MAX_TAGS)
end_define

begin_comment
comment|/* **    The maximum number of segments a transfer is split into. */
end_comment

begin_define
define|#
directive|define
name|MAX_SCATTER
value|(33)
end_define

begin_comment
comment|/* **    The maximum transfer length (should be>= 64k). **    MUST NOT be greater than (MAX_SCATTER-1) * NBPG. */
end_comment

begin_define
define|#
directive|define
name|MAX_SIZE
value|((MAX_SCATTER-1) * NBPG)
end_define

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Include files ** **========================================================== */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__NetBSD__
end_ifndef

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NetBSD__
end_ifndef

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/ncrreg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_include
include|#
directive|include
file|<i386/pci/ncrreg.h>
end_include

begin_include
include|#
directive|include
file|<i386/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<i386/pci/pcireg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD */
end_comment

begin_include
include|#
directive|include
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	Debugging tags ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|DEBUG_ALLOC
value|(0x0001)
end_define

begin_define
define|#
directive|define
name|DEBUG_PHASE
value|(0x0002)
end_define

begin_define
define|#
directive|define
name|DEBUG_POLL
value|(0x0004)
end_define

begin_define
define|#
directive|define
name|DEBUG_QUEUE
value|(0x0008)
end_define

begin_define
define|#
directive|define
name|DEBUG_RESULT
value|(0x0010)
end_define

begin_define
define|#
directive|define
name|DEBUG_SCATTER
value|(0x0020)
end_define

begin_define
define|#
directive|define
name|DEBUG_SCRIPT
value|(0x0040)
end_define

begin_define
define|#
directive|define
name|DEBUG_TINY
value|(0x0080)
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMING
value|(0x0100)
end_define

begin_define
define|#
directive|define
name|DEBUG_NEGO
value|(0x0200)
end_define

begin_define
define|#
directive|define
name|DEBUG_TAGS
value|(0x0400)
end_define

begin_define
define|#
directive|define
name|DEBUG_FREEZE
value|(0x0800)
end_define

begin_define
define|#
directive|define
name|DEBUG_RESTART
value|(0x1000)
end_define

begin_comment
comment|/* **    Enable/Disable debug messages. **    Can be changed at runtime too. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCSI_DEBUG_FLAGS
end_ifdef

begin_define
define|#
directive|define
name|DEBUG_FLAGS
value|ncr_debug;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SCSI_DEBUG_FLAGS */
end_comment

begin_define
define|#
directive|define
name|SCSI_DEBUG_FLAGS
value|0
end_define

begin_define
define|#
directive|define
name|DEBUG_FLAGS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCSI_DEBUG_FLAGS */
end_comment

begin_comment
comment|/*========================================================== ** **	assert () ** **========================================================== ** **	modified copy from 386bsd:/usr/include/sys/assert.h ** **---------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|expression
parameter_list|)
value|{ \ 	if (!(expression)) { \ 		(void)printf(\ 			"assertion \"%s\" failed: file \"%s\", line %d\n", \ 			#expression, \ 			__FILE__, __LINE__); \ 	} \ }
end_define

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	Access to the controller chip. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|INB
parameter_list|(
name|r
parameter_list|)
value|(np->reg->r)
end_define

begin_define
define|#
directive|define
name|INW
parameter_list|(
name|r
parameter_list|)
value|(np->reg->r)
end_define

begin_define
define|#
directive|define
name|INL
parameter_list|(
name|r
parameter_list|)
value|(np->reg->r)
end_define

begin_define
define|#
directive|define
name|OUTB
parameter_list|(
name|r
parameter_list|,
name|val
parameter_list|)
value|np->reg->r = val
end_define

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|r
parameter_list|,
name|val
parameter_list|)
value|np->reg->r = val
end_define

begin_define
define|#
directive|define
name|OUTL
parameter_list|(
name|r
parameter_list|,
name|val
parameter_list|)
value|np->reg->r = val
end_define

begin_comment
comment|/*========================================================== ** **	Command control block states. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|HS_IDLE
value|(0)
end_define

begin_define
define|#
directive|define
name|HS_BUSY
value|(1)
end_define

begin_define
define|#
directive|define
name|HS_NEGOTIATE
value|(2)
end_define

begin_comment
comment|/* sync/wide data transfer*/
end_comment

begin_define
define|#
directive|define
name|HS_DISCONNECT
value|(3)
end_define

begin_comment
comment|/* Disconnected by target */
end_comment

begin_define
define|#
directive|define
name|HS_COMPLETE
value|(4)
end_define

begin_define
define|#
directive|define
name|HS_SEL_TIMEOUT
value|(5)
end_define

begin_comment
comment|/* Selection timeout      */
end_comment

begin_define
define|#
directive|define
name|HS_RESET
value|(6)
end_define

begin_comment
comment|/* SCSI reset             */
end_comment

begin_define
define|#
directive|define
name|HS_ABORTED
value|(7)
end_define

begin_comment
comment|/* Transfer aborted       */
end_comment

begin_define
define|#
directive|define
name|HS_TIMEOUT
value|(8)
end_define

begin_comment
comment|/* Software timeout       */
end_comment

begin_define
define|#
directive|define
name|HS_FAIL
value|(9)
end_define

begin_comment
comment|/* SCSI or PCI bus errors */
end_comment

begin_define
define|#
directive|define
name|HS_UNEXPECTED
value|(10)
end_define

begin_comment
comment|/* Unexpected disconnect  */
end_comment

begin_define
define|#
directive|define
name|HS_DONEMASK
value|(0xfc)
end_define

begin_comment
comment|/*========================================================== ** **	Software Interrupt Codes ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|SIR_SENSE_RESTART
value|(1)
end_define

begin_define
define|#
directive|define
name|SIR_SENSE_FAILED
value|(2)
end_define

begin_define
define|#
directive|define
name|SIR_STALL_RESTART
value|(3)
end_define

begin_define
define|#
directive|define
name|SIR_STALL_QUEUE
value|(4)
end_define

begin_define
define|#
directive|define
name|SIR_NEGO_SYNC
value|(5)
end_define

begin_define
define|#
directive|define
name|SIR_NEGO_WIDE
value|(6)
end_define

begin_define
define|#
directive|define
name|SIR_NEGO_FAILED
value|(7)
end_define

begin_define
define|#
directive|define
name|SIR_NEGO_PROTO
value|(8)
end_define

begin_define
define|#
directive|define
name|SIR_REJECT_RECEIVED
value|(9)
end_define

begin_define
define|#
directive|define
name|SIR_REJECT_SENT
value|(10)
end_define

begin_define
define|#
directive|define
name|SIR_IGN_RESIDUE
value|(11)
end_define

begin_define
define|#
directive|define
name|SIR_MISSING_SAVE
value|(12)
end_define

begin_define
define|#
directive|define
name|SIR_MAX
value|(12)
end_define

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	Extended error codes. **	xerr_status field of struct ccb. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|XE_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|XE_EXTRA_DATA
value|(1)
end_define

begin_comment
comment|/* unexpected data phase */
end_comment

begin_define
define|#
directive|define
name|XE_BAD_PHASE
value|(2)
end_define

begin_comment
comment|/* illegal phase (4/5)   */
end_comment

begin_comment
comment|/*========================================================== ** **	Negotiation status. **	nego_status field	of struct ccb. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|NS_SYNC
value|(1)
end_define

begin_define
define|#
directive|define
name|NS_WIDE
value|(2)
end_define

begin_comment
comment|/*========================================================== ** **	"Special features" of targets. **	quirks field		of struct tcb. **	actualquirks field	of struct ccb. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|QUIRK_AUTOSAVE
value|(0x01)
end_define

begin_define
define|#
directive|define
name|QUIRK_NOMSG
value|(0x02)
end_define

begin_define
define|#
directive|define
name|QUIRK_UPDATE
value|(0x80)
end_define

begin_comment
comment|/*========================================================== ** **	Capability bits in Inquire response byte 7. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|INQ7_QUEUE
value|(0x02)
end_define

begin_define
define|#
directive|define
name|INQ7_SYNC
value|(0x10)
end_define

begin_define
define|#
directive|define
name|INQ7_WIDE16
value|(0x20)
end_define

begin_comment
comment|/*========================================================== ** **	Misc. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|CCB_MAGIC
value|(0xf2691ad2)
end_define

begin_define
define|#
directive|define
name|MAX_TAGS
value|(16)
end_define

begin_comment
comment|/* hard limit */
end_comment

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	OS dependencies. ** **========================================================== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__NetBSD__
end_ifndef

begin_define
define|#
directive|define
name|ANCIENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__NetBSD__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__FreeBSD__*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ANCIENT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|extern
name|int
name|splbio
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|splx
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wakeup
parameter_list|(
name|void
modifier|*
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tsleep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DELAY
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|scsi_attachdevs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|timeout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|untimeout
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_define
define|#
directive|define
name|bio_imask
value|biomask
end_define

begin_define
define|#
directive|define
name|LUN
value|lu
end_define

begin_define
define|#
directive|define
name|TARGET
value|targ
end_define

begin_define
define|#
directive|define
name|PRINT_ADDR
parameter_list|(
name|xp
parameter_list|)
value|printf ("ncr0: targ %d lun %d ",xp->targ,xp->lu)
end_define

begin_define
define|#
directive|define
name|INT32
value|int
end_define

begin_define
define|#
directive|define
name|U_INT32
value|long
end_define

begin_define
define|#
directive|define
name|TIMEOUT
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !ANCIENT */
end_comment

begin_define
define|#
directive|define
name|LUN
value|sc_link->lun
end_define

begin_define
define|#
directive|define
name|TARGET
value|sc_link->target
end_define

begin_define
define|#
directive|define
name|PRINT_ADDR
parameter_list|(
name|xp
parameter_list|)
value|sc_print_addr(xp->sc_link)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|INT32
value|int
end_define

begin_define
define|#
directive|define
name|U_INT32
value|u_int
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|(void*)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*__NetBSD__*/
end_comment

begin_define
define|#
directive|define
name|INT32
value|int32
end_define

begin_define
define|#
directive|define
name|U_INT32
value|u_int32
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|(timeout_func_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__NetBSD__*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANCIENT */
end_comment

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **	Declaration of structs. ** **========================================================== */
end_comment

begin_struct_decl
struct_decl|struct
name|tcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|script
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|ncb
modifier|*
name|ncb_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tcb
modifier|*
name|tcb_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|lcb
modifier|*
name|lcb_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ccb
modifier|*
name|ccb_p
typedef|;
end_typedef

begin_struct
struct|struct
name|link
block|{
name|u_long
name|l_cmd
decl_stmt|;
name|u_long
name|l_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usrcmd
block|{
name|u_long
name|target
decl_stmt|;
name|u_long
name|lun
decl_stmt|;
name|u_long
name|data
decl_stmt|;
name|u_long
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UC_SETSYNC
value|10
end_define

begin_define
define|#
directive|define
name|UC_SETTAGS
value|11
end_define

begin_define
define|#
directive|define
name|UC_SETDEBUG
value|12
end_define

begin_define
define|#
directive|define
name|UC_SETORDER
value|13
end_define

begin_define
define|#
directive|define
name|UC_SETWIDE
value|14
end_define

begin_define
define|#
directive|define
name|UC_SETFLAG
value|15
end_define

begin_define
define|#
directive|define
name|UF_TRACE
value|(0x01)
end_define

begin_comment
comment|/*========================================================== ** **	Access to fields of structs. ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
value|((size_t)(&((type *)0)->member))
end_define

begin_escape
end_escape

begin_comment
comment|/*--------------------------------------- ** **	Timestamps for profiling ** **--------------------------------------- */
end_comment

begin_struct
struct|struct
name|tstamp
block|{
name|struct
name|timeval
name|start
decl_stmt|;
name|struct
name|timeval
name|end
decl_stmt|;
name|struct
name|timeval
name|select
decl_stmt|;
name|struct
name|timeval
name|command
decl_stmt|;
name|struct
name|timeval
name|data
decl_stmt|;
name|struct
name|timeval
name|status
decl_stmt|;
name|struct
name|timeval
name|disconnect
decl_stmt|;
name|struct
name|timeval
name|reselect
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **	profiling data (per device) */
end_comment

begin_struct
struct|struct
name|profile
block|{
name|u_long
name|num_trans
decl_stmt|;
name|u_long
name|num_bytes
decl_stmt|;
name|u_long
name|num_disc
decl_stmt|;
name|u_long
name|num_break
decl_stmt|;
name|u_long
name|num_int
decl_stmt|;
name|u_long
name|num_fly
decl_stmt|;
name|u_long
name|ms_setup
decl_stmt|;
name|u_long
name|ms_data
decl_stmt|;
name|u_long
name|ms_disc
decl_stmt|;
name|u_long
name|ms_post
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:		TARGET control block ** **========================================================== */
end_comment

begin_struct
struct|struct
name|tcb
block|{
comment|/* 	**	during reselection the ncr jumps to this point 	**	with SFBR set to the encoded TARGET number 	**	with bit 7 set. 	**	if it's not this target, jump to the next. 	** 	**	JUMP  IF (SFBR != #TARGET#) 	**	@(next tcb) 	*/
name|struct
name|link
name|jump_tcb
decl_stmt|;
comment|/* 	**	load the actual values for the sxfer and the scntl3 	**	register (sync/wide mode). 	** 	**	SCR_COPY (1); 	**	@(sval field of this tcb) 	**	@(sxfer register) 	**	SCR_COPY (1); 	**	@(wval field of this tcb) 	**	@(scntl3 register) 	*/
name|ncrcmd
name|getscr
index|[
literal|6
index|]
decl_stmt|;
comment|/* 	**	if next message is "identify" 	**	then load the message to SFBR, 	**	else load 0 to SFBR. 	** 	**	CALL 	**<RESEL_LUN> 	*/
name|struct
name|link
name|call_lun
decl_stmt|;
comment|/* 	**	now look for the right lun. 	** 	**	JUMP 	**	@(first ccb of this lun) 	*/
name|struct
name|link
name|jump_lcb
decl_stmt|;
comment|/* 	**	pointer to interrupted getcc ccb 	*/
name|ccb_p
name|hold_cp
decl_stmt|;
comment|/* 	**	statistical data 	*/
name|u_long
name|transfers
decl_stmt|;
name|u_long
name|bytes
decl_stmt|;
comment|/* 	**	user settable limits for sync transfer 	**	and tagged commands. 	*/
name|u_char
name|usrsync
decl_stmt|;
name|u_char
name|usrtags
decl_stmt|;
name|u_char
name|usrwide
decl_stmt|;
name|u_char
name|usrflag
decl_stmt|;
comment|/* 	**	negotiation of wide and synch transfer. 	**	device quirks. 	*/
comment|/*0*/
name|u_char
name|minsync
decl_stmt|;
comment|/*1*/
name|u_char
name|sval
decl_stmt|;
comment|/*2*/
name|u_short
name|period
decl_stmt|;
comment|/*0*/
name|u_char
name|maxoffs
decl_stmt|;
comment|/*1*/
name|u_char
name|quirks
decl_stmt|;
comment|/*2*/
name|u_char
name|widedone
decl_stmt|;
comment|/*3*/
name|u_char
name|wval
decl_stmt|;
comment|/* 	**	inquire data 	*/
define|#
directive|define
name|MAX_INQUIRE
value|36
name|u_char
name|inqdata
index|[
name|MAX_INQUIRE
index|]
decl_stmt|;
comment|/* 	**	the lcb's of this tcb 	*/
name|lcb_p
name|lp
index|[
name|MAX_LUN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:		LUN control block ** **========================================================== */
end_comment

begin_struct
struct|struct
name|lcb
block|{
comment|/* 	**	during reselection the ncr jumps to this point 	**	with SFBR set to the "Identify" message. 	**	if it's not this lun, jump to the next. 	** 	**	JUMP  IF (SFBR == #LUN#) 	**	@(next lcb of this target) 	*/
name|struct
name|link
name|jump_lcb
decl_stmt|;
comment|/* 	**	if next message is "simple tag", 	**	then load the tag to SFBR, 	**	else load 0 to SFBR. 	** 	**	CALL 	**<RESEL_TAG> 	*/
name|struct
name|link
name|call_tag
decl_stmt|;
comment|/* 	**	now look for the right ccb. 	** 	**	JUMP 	**	@(first ccb of this lun) 	*/
name|struct
name|link
name|jump_ccb
decl_stmt|;
comment|/* 	**	start of the ccb chain 	*/
name|ccb_p
name|next_ccb
decl_stmt|;
comment|/* 	**	Control of tagged queueing 	*/
name|u_char
name|reqccbs
decl_stmt|;
name|u_char
name|actccbs
decl_stmt|;
name|u_char
name|reqlink
decl_stmt|;
name|u_char
name|actlink
decl_stmt|;
name|u_char
name|usetags
decl_stmt|;
name|u_char
name|lasttag
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:     COMMAND control block ** **========================================================== ** **	This substructure is copied from the ccb to a **	global address after selection (or reselection) **	and copied back before disconnect. ** **	These fields are accessible to the script processor. ** **---------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|head
block|{
comment|/* 	**	Execution of a ccb starts at this point. 	**	It's a jump to the "SELECT" label 	**	of the script. 	** 	**	After successful selection the script 	**	processor overwrites it with a jump to 	**	the IDLE label of the script. 	*/
name|struct
name|link
name|launch
decl_stmt|;
comment|/* 	**	Saved data pointer. 	**	Points to the position in the script 	**	responsible for the actual transfer 	**	of data. 	**	It's written after reception of a 	**	"SAVE_DATA_POINTER" message. 	**	The goalpointer points after 	**	the last transfer command. 	*/
name|u_long
name|savep
decl_stmt|;
name|u_long
name|lastp
decl_stmt|;
name|u_long
name|goalp
decl_stmt|;
comment|/* 	**	The virtual address of the ccb 	**	containing this header. 	*/
name|ccb_p
name|cp
decl_stmt|;
comment|/* 	**	space for some timestamps to gather 	**	profiling data about devices and this driver. 	*/
name|struct
name|tstamp
name|stamp
decl_stmt|;
comment|/* 	**	status fields. 	*/
name|u_char
name|status
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **	The status bytes are used by the host and the script processor. ** **	The first four byte are copied to the scratchb register **	(declared as scr0..scr3 in ncr_reg.h) just after the select/reselect, **	and copied back just after disconnecting. **	Inside the script the XX_REG are used. ** **	The last four bytes are used inside the script by "COPY" commands. **	Because source and destination must have the same alignment **	in a longword, the fields HAVE to be on the selected offsets. **		xerr_st	(4)	0	(0x34)	scratcha **		sync_st	(5)	1	(0x05)	sxfer **		wide_st	(7)	3	(0x03)	scntl3 */
end_comment

begin_comment
comment|/* **	First four bytes (script) */
end_comment

begin_define
define|#
directive|define
name|QU_REG
value|scr0
end_define

begin_define
define|#
directive|define
name|HS_REG
value|scr1
end_define

begin_define
define|#
directive|define
name|HS_PRT
value|nc_scr1
end_define

begin_define
define|#
directive|define
name|SS_REG
value|scr2
end_define

begin_define
define|#
directive|define
name|PS_REG
value|scr3
end_define

begin_comment
comment|/* **	First four bytes (host) */
end_comment

begin_define
define|#
directive|define
name|actualquirks
value|phys.header.status[0]
end_define

begin_define
define|#
directive|define
name|host_status
value|phys.header.status[1]
end_define

begin_define
define|#
directive|define
name|scsi_status
value|phys.header.status[2]
end_define

begin_define
define|#
directive|define
name|parity_status
value|phys.header.status[3]
end_define

begin_comment
comment|/* **	Last four bytes (script) */
end_comment

begin_define
define|#
directive|define
name|xerr_st
value|header.status[4]
end_define

begin_comment
comment|/* MUST be ==0 mod 4 */
end_comment

begin_define
define|#
directive|define
name|sync_st
value|header.status[5]
end_define

begin_comment
comment|/* MUST be ==1 mod 4 */
end_comment

begin_define
define|#
directive|define
name|nego_st
value|header.status[6]
end_define

begin_define
define|#
directive|define
name|wide_st
value|header.status[7]
end_define

begin_comment
comment|/* MUST be ==3 mod 4 */
end_comment

begin_comment
comment|/* **	Last four bytes (host) */
end_comment

begin_define
define|#
directive|define
name|xerr_status
value|phys.xerr_st
end_define

begin_define
define|#
directive|define
name|sync_status
value|phys.sync_st
end_define

begin_define
define|#
directive|define
name|nego_status
value|phys.nego_st
end_define

begin_define
define|#
directive|define
name|wide_status
value|phys.wide_st
end_define

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:     Data structure block ** **========================================================== ** **	During execution of a ccb by the script processor, **	the DSA (data structure address) register points **	to this substructure of the ccb. **	This substructure contains the header with **	the script-processor-changable data and **	data blocks for the indirect move commands. ** **---------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|dsb
block|{
comment|/* 	**	Header. 	**	Has to be the first entry, 	**	because it's jumped to by the 	**	script processor 	*/
name|struct
name|head
name|header
decl_stmt|;
comment|/* 	**	Table data for Script 	*/
name|struct
name|scr_tblsel
name|select
decl_stmt|;
name|struct
name|scr_tblmove
name|smsg
decl_stmt|;
name|struct
name|scr_tblmove
name|smsg2
decl_stmt|;
name|struct
name|scr_tblmove
name|cmd
decl_stmt|;
name|struct
name|scr_tblmove
name|sense
decl_stmt|;
name|struct
name|scr_tblmove
name|data
index|[
name|MAX_SCATTER
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:     Command control block. ** **========================================================== ** **	During execution of a ccb by the script processor, **	the DSA (data structure address) register points **	to this substructure of the ccb. **	This substructure contains the header with **	the script-processor-changable data and then **	data blocks for the indirect move commands. ** **---------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|ccb
block|{
comment|/* 	**	during reselection the ncr jumps to this point. 	**	If a "SIMPLE_TAG" message was received, 	**	then SFBR is set to the tag. 	**	else SFBR is set to 0 	**	If looking for another tag, jump to the next ccb. 	** 	**	JUMP  IF (SFBR != #TAG#) 	**	@(next ccb of this lun) 	*/
name|struct
name|link
name|jump_ccb
decl_stmt|;
comment|/* 	**	After execution of this call, the return address 	**	(in  the TEMP register) points to the following 	**	data structure block. 	**	So copy it to the DSA register, and start 	**	processing of this data structure. 	** 	**	CALL 	**<RESEL_TMP> 	*/
name|struct
name|link
name|call_tmp
decl_stmt|;
comment|/* 	**	This is the data structure which is 	**	to be executed by the script processor. 	*/
name|struct
name|dsb
name|phys
decl_stmt|;
comment|/* 	**	If a data transfer phase is terminated too early 	**	(after reception of a message (i.e. DISCONNECT)), 	**	we have to prepare a mini script to transfer 	**	the rest of the data. 	*/
name|u_long
name|patch
index|[
literal|8
index|]
decl_stmt|;
comment|/* 	**	The general SCSI driver provides a 	**	pointer to a control block. 	*/
name|struct
name|scsi_xfer
modifier|*
name|xfer
decl_stmt|;
ifdef|#
directive|ifdef
name|ANCIENT
comment|/* 	**	We copy the SCSI command, because it 	**	may be volatile (on the stack). 	** 	*/
name|struct
name|scsi_generic
name|cmd
decl_stmt|;
endif|#
directive|endif
comment|/* ANCIENT */
comment|/* 	**	We prepare a message to be sent after selection, 	**	and a second one to be sent after getcc selection. 	**      Contents are IDENTIFY and SIMPLE_TAG. 	**	While negotiating sync or wide transfer, 	**	a SDTM or WDTM message is appended. 	*/
name|u_char
name|scsi_smsg
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|scsi_smsg2
index|[
literal|8
index|]
decl_stmt|;
comment|/* 	**	Lock this ccb. 	**	Flag is used while looking for a free ccb. 	*/
name|u_long
name|magic
decl_stmt|;
comment|/* 	**	Completion time out for this job. 	**	It's set to time of start + allowed number of seconds. 	*/
name|u_long
name|tlimit
decl_stmt|;
comment|/* 	**	All ccbs of one hostadapter are linked. 	*/
name|ccb_p
name|link_ccb
decl_stmt|;
comment|/* 	**	All ccbs of one target/lun are linked. 	*/
name|ccb_p
name|next_ccb
decl_stmt|;
comment|/* 	**	Tag for this transfer. 	**	It's patched into jump_ccb. 	**	If it's not zero, a SIMPLE_TAG 	**	message is included in smsg. 	*/
name|u_char
name|tag
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** **      Declaration of structs:     NCR device descriptor ** **========================================================== */
end_comment

begin_struct
struct|struct
name|ncb
block|{
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|device
name|sc_dev
decl_stmt|;
name|struct
name|intrhand
name|sc_ih
decl_stmt|;
else|#
directive|else
comment|/* !__NetBSD__ */
name|int
name|unit
decl_stmt|;
endif|#
directive|endif
comment|/* __NetBSD__ */
comment|/*----------------------------------------------- 	**	Scripts .. 	**----------------------------------------------- 	** 	**	During reselection the ncr jumps to this point. 	**	The SFBR register is loaded with the encoded target id. 	** 	**	Jump to the first target. 	** 	**	JUMP 	**	@(next tcb) 	*/
name|struct
name|link
name|jump_tcb
decl_stmt|;
comment|/*----------------------------------------------- 	**	Configuration .. 	**----------------------------------------------- 	** 	**	virtual and physical addresses 	**	of the 53c810 chip. 	*/
name|vm_offset_t
name|vaddr
decl_stmt|;
name|vm_offset_t
name|paddr
decl_stmt|;
comment|/* 	**	pointer to the chip's registers. 	*/
specifier|volatile
name|struct
name|ncr_reg
modifier|*
name|reg
decl_stmt|;
comment|/* 	**	A copy of the script, relocated for this ncb. 	*/
name|struct
name|script
modifier|*
name|script
decl_stmt|;
name|u_long
name|p_script
decl_stmt|;
comment|/* 	**	The SCSI address of the host adapter. 	*/
name|u_char
name|myaddr
decl_stmt|;
comment|/* 	**	timing parameters 	*/
name|u_char
name|ns_async
decl_stmt|;
name|u_char
name|ns_sync
decl_stmt|;
name|u_char
name|rv_scntl3
decl_stmt|;
ifndef|#
directive|ifndef
name|ANCIENT
comment|/*----------------------------------------------- 	**	Link to the generic SCSI driver 	**----------------------------------------------- 	*/
name|struct
name|scsi_link
name|sc_link
decl_stmt|;
endif|#
directive|endif
comment|/* ANCIENT */
comment|/*----------------------------------------------- 	**	Job control 	**----------------------------------------------- 	** 	**	Commands from user 	*/
name|struct
name|usrcmd
name|user
decl_stmt|;
name|u_char
name|order
decl_stmt|;
comment|/* 	**	Target data 	*/
name|struct
name|tcb
name|target
index|[
name|MAX_TARGET
index|]
decl_stmt|;
comment|/* 	**	Start queue. 	*/
name|u_long
name|squeue
index|[
name|MAX_START
index|]
decl_stmt|;
name|u_short
name|squeueput
decl_stmt|;
name|u_short
name|actccbs
decl_stmt|;
comment|/* 	**	Timeout handler 	*/
name|u_long
name|heartbeat
decl_stmt|;
name|u_short
name|ticks
decl_stmt|;
name|u_short
name|latetime
decl_stmt|;
name|u_long
name|lasttime
decl_stmt|;
comment|/*----------------------------------------------- 	**	Debug and profiling 	**----------------------------------------------- 	** 	**	register dump 	*/
name|struct
name|ncr_reg
name|regdump
decl_stmt|;
name|struct
name|timeval
name|regtime
decl_stmt|;
comment|/* 	**	Profiling data 	*/
name|struct
name|profile
name|profile
decl_stmt|;
name|u_long
name|disc_phys
decl_stmt|;
name|u_long
name|disc_ref
decl_stmt|;
comment|/* 	**	The global header. 	**	Accessible to both the host and the 	**	script-processor. 	*/
name|struct
name|head
name|header
decl_stmt|;
comment|/* 	**	The global control block. 	**	It's used only during the configuration phase. 	**	A target control block will be created 	**	after the first successful transfer. 	*/
name|struct
name|ccb
name|ccb
decl_stmt|;
comment|/* 	**	message buffers. 	**	Should be longword aligned, 	**	because they're written with a 	**	COPY script command. 	*/
name|u_char
name|msgout
index|[
literal|8
index|]
decl_stmt|;
name|u_char
name|msgin
index|[
literal|8
index|]
decl_stmt|;
name|u_long
name|lastmsg
decl_stmt|;
comment|/* 	**	Buffer for STATUS_IN phase. 	*/
name|u_char
name|scratch
decl_stmt|;
comment|/* 	**	controller chip dependent maximal transfer width. 	*/
name|u_char
name|maxwide
decl_stmt|;
comment|/* 	**	lockout of execption handler call while starting command. 	*/
name|u_char
name|lock
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Script for NCR-Processor. ** **	Use ncr_script_fill() to create the variable parts. **	Use ncr_script_copy_and_bind() to make a copy and **	bind to physical addresses. ** ** **========================================================== ** **	We have to know the offsets of all labels before **	we reach them (for forward jumps). **	Therefore we declare a struct here. **	If you make changes inside the script, **	DONT FORGET TO CHANGE THE LENGTHS HERE! ** **---------------------------------------------------------- */
end_comment

begin_escape
end_escape

begin_struct
struct|struct
name|script
block|{
name|ncrcmd
name|start
index|[
literal|7
index|]
decl_stmt|;
name|ncrcmd
name|start0
index|[
literal|2
index|]
decl_stmt|;
name|ncrcmd
name|start1
index|[
literal|3
index|]
decl_stmt|;
name|ncrcmd
name|startpos
index|[
literal|1
index|]
decl_stmt|;
name|ncrcmd
name|tryloop
index|[
name|MAX_START
operator|*
literal|5
operator|+
literal|2
index|]
decl_stmt|;
name|ncrcmd
name|trysel
index|[
literal|8
index|]
decl_stmt|;
name|ncrcmd
name|skip
index|[
literal|8
index|]
decl_stmt|;
name|ncrcmd
name|skip2
index|[
literal|3
index|]
decl_stmt|;
name|ncrcmd
name|idle
index|[
literal|2
index|]
decl_stmt|;
name|ncrcmd
name|select
index|[
literal|24
index|]
decl_stmt|;
name|ncrcmd
name|prepare
index|[
literal|4
index|]
decl_stmt|;
name|ncrcmd
name|loadpos
index|[
literal|14
index|]
decl_stmt|;
name|ncrcmd
name|prepare2
index|[
literal|24
index|]
decl_stmt|;
name|ncrcmd
name|setmsg
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|clrack
index|[
literal|2
index|]
decl_stmt|;
name|ncrcmd
name|dispatch
index|[
literal|31
index|]
decl_stmt|;
name|ncrcmd
name|no_data
index|[
literal|17
index|]
decl_stmt|;
name|ncrcmd
name|checkatn
index|[
literal|10
index|]
decl_stmt|;
name|ncrcmd
name|command
index|[
literal|15
index|]
decl_stmt|;
name|ncrcmd
name|status
index|[
literal|27
index|]
decl_stmt|;
name|ncrcmd
name|msg_in
index|[
literal|26
index|]
decl_stmt|;
name|ncrcmd
name|msg_bad
index|[
literal|6
index|]
decl_stmt|;
name|ncrcmd
name|msg_parity
index|[
literal|6
index|]
decl_stmt|;
name|ncrcmd
name|msg_reject
index|[
literal|8
index|]
decl_stmt|;
name|ncrcmd
name|msg_ign_residue
index|[
literal|32
index|]
decl_stmt|;
name|ncrcmd
name|msg_extended
index|[
literal|18
index|]
decl_stmt|;
name|ncrcmd
name|msg_ext_2
index|[
literal|18
index|]
decl_stmt|;
name|ncrcmd
name|msg_wdtr
index|[
literal|27
index|]
decl_stmt|;
name|ncrcmd
name|msg_ext_3
index|[
literal|18
index|]
decl_stmt|;
name|ncrcmd
name|msg_sdtr
index|[
literal|27
index|]
decl_stmt|;
name|ncrcmd
name|complete
index|[
literal|13
index|]
decl_stmt|;
name|ncrcmd
name|cleanup
index|[
literal|12
index|]
decl_stmt|;
name|ncrcmd
name|cleanup0
index|[
literal|11
index|]
decl_stmt|;
name|ncrcmd
name|signal
index|[
literal|10
index|]
decl_stmt|;
name|ncrcmd
name|save_dp
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|restore_dp
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|disconnect
index|[
literal|12
index|]
decl_stmt|;
name|ncrcmd
name|disconnect0
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|disconnect1
index|[
literal|23
index|]
decl_stmt|;
name|ncrcmd
name|msg_out
index|[
literal|9
index|]
decl_stmt|;
name|ncrcmd
name|msg_out_done
index|[
literal|7
index|]
decl_stmt|;
name|ncrcmd
name|msg_out_abort
index|[
literal|10
index|]
decl_stmt|;
name|ncrcmd
name|getcc
index|[
literal|4
index|]
decl_stmt|;
name|ncrcmd
name|getcc1
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|getcc2
index|[
literal|33
index|]
decl_stmt|;
name|ncrcmd
name|getcc3
index|[
literal|10
index|]
decl_stmt|;
name|ncrcmd
name|badgetcc
index|[
literal|6
index|]
decl_stmt|;
name|ncrcmd
name|reselect
index|[
literal|12
index|]
decl_stmt|;
name|ncrcmd
name|reselect2
index|[
literal|6
index|]
decl_stmt|;
name|ncrcmd
name|resel_tmp
index|[
literal|5
index|]
decl_stmt|;
name|ncrcmd
name|resel_lun
index|[
literal|18
index|]
decl_stmt|;
name|ncrcmd
name|resel_tag
index|[
literal|24
index|]
decl_stmt|;
name|ncrcmd
name|data_in
index|[
name|MAX_SCATTER
operator|*
literal|4
operator|+
literal|7
index|]
decl_stmt|;
name|ncrcmd
name|data_out
index|[
name|MAX_SCATTER
operator|*
literal|4
operator|+
literal|7
index|]
decl_stmt|;
name|ncrcmd
name|aborttag
index|[
literal|4
index|]
decl_stmt|;
name|ncrcmd
name|abort
index|[
literal|22
index|]
decl_stmt|;
name|ncrcmd
name|snooptest
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Function headers. ** ** **========================================================== */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
specifier|static
name|void
name|ncr_alloc_ccb
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|struct
name|scsi_xfer
modifier|*
name|xp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_complete
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|ccb_p
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ncr_delta
parameter_list|(
name|struct
name|timeval
modifier|*
name|from
parameter_list|,
name|struct
name|timeval
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_exception
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_free_ccb
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|ccb_p
name|cp
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_getclock
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|ccb_p
name|ncr_get_ccb
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|u_long
name|flags
parameter_list|,
name|u_long
name|t
parameter_list|,
name|u_long
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|U_INT32
name|ncr_info
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_init
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
name|u_long
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ncr_intr
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_int_ma
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_int_sir
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_int_sto
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_SCSICONF
end_ifndef

begin_function_decl
specifier|static
name|u_long
name|ncr_lookup
parameter_list|(
name|char
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_SCSICONF */
end_comment

begin_function_decl
specifier|static
name|void
name|ncr_min_phys
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_negotiate
parameter_list|(
name|struct
name|ncb
modifier|*
name|np
parameter_list|,
name|struct
name|tcb
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_opennings
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|lcb_p
name|lp
parameter_list|,
name|struct
name|scsi_xfer
modifier|*
name|xp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncb_profile
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|ccb_p
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_script_copy_and_bind
parameter_list|(
name|struct
name|script
modifier|*
name|script
parameter_list|,
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_script_fill
parameter_list|(
name|struct
name|script
modifier|*
name|scr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ncr_scatter
parameter_list|(
name|struct
name|dsb
modifier|*
name|phys
parameter_list|,
name|u_long
name|vaddr
parameter_list|,
name|u_long
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_setmaxtags
parameter_list|(
name|tcb_p
name|tp
parameter_list|,
name|u_long
name|usrtags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_setsync
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|ccb_p
name|cp
parameter_list|,
name|u_char
name|sxfer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_settags
parameter_list|(
name|tcb_p
name|tp
parameter_list|,
name|lcb_p
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_setwide
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|ccb_p
name|cp
parameter_list|,
name|u_char
name|wide
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ncr_show_msg
parameter_list|(
name|u_char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ncr_snooptest
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|INT32
name|ncr_start
parameter_list|(
name|struct
name|scsi_xfer
modifier|*
name|xp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_timeout
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_usercmd
parameter_list|(
name|ncb_p
name|np
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_wakeup
parameter_list|(
name|ncb_p
name|np
parameter_list|,
name|u_long
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_function_decl
specifier|static
name|int
name|ncr_probe
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_attach
parameter_list|(
name|struct
name|device
modifier|*
parameter_list|,
name|struct
name|device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__NetBSD */
end_comment

begin_function_decl
specifier|static
name|char
modifier|*
name|ncr_probe
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|ncr_attach
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NetBSD__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Global static data. ** ** **========================================================== */
end_comment

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"\n$Id: ncr.c,v 1.15 1995/02/02 12:36:16 davidg Exp $\n"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|ncr_version
init|=
name|NCR_VERSION
operator|+
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|ncb
argument_list|)
operator|*
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|ccb
argument_list|)
operator|*
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|lcb
argument_list|)
operator|*
operator|(
name|u_long
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|tcb
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__NetBSD__
end_ifndef

begin_decl_stmt
name|u_long
name|nncr
init|=
name|MAX_UNITS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ncb_p
name|ncrp
index|[
name|MAX_UNITS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|ncr_debug
init|=
name|SCSI_DEBUG_FLAGS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ncr_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to be alligned _NOT_ static */
end_comment

begin_comment
comment|/* **	SCSI cmd to get the SCSI sense data */
end_comment

begin_decl_stmt
specifier|static
name|u_char
name|rs_cmd
index|[
literal|6
index|]
init|=
block|{
literal|0x03
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|scsi_sense_data
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Global static data:	auto configure ** ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|NCR_810_ID
value|(0x00011000ul)
end_define

begin_define
define|#
directive|define
name|NCR_825_ID
value|(0x00031000ul)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_decl_stmt
name|struct
name|cfdriver
name|ncrcd
init|=
block|{
name|NULL
block|,
literal|"ncr"
block|,
name|ncr_probe
block|,
name|ncr_attach
block|,
name|DV_DISK
block|,
expr|sizeof
operator|(
expr|struct
name|ncb
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__NetBSD__ */
end_comment

begin_decl_stmt
specifier|static
name|u_long
name|ncr_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pci_device
name|ncr_device
init|=
block|{
literal|"ncr"
block|,
name|ncr_probe
block|,
name|ncr_attach
block|,
operator|&
name|ncr_count
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DATA_SET
argument_list|(
name|pcidevice_set
argument_list|,
name|ncr_device
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NetBSD__ */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|ANCIENT
end_ifndef

begin_decl_stmt
name|struct
name|scsi_adapter
name|ncr_switch
init|=
block|{
name|ncr_start
block|,
name|ncr_min_phys
block|,
literal|0
block|,
literal|0
block|,
name|ncr_info
block|,
literal|"ncr"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|scsi_device
name|ncr_dev
init|=
block|{
name|NULL
block|,
comment|/* Use default error handler */
name|NULL
block|,
comment|/* have a queue, served by this */
name|NULL
block|,
comment|/* have no async handler */
name|NULL
block|,
comment|/* Use default 'done' routine */
literal|"ncr"
block|, }
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ANCIENT */
end_comment

begin_decl_stmt
name|struct
name|scsi_switch
name|ncr_switch
init|=
block|{
name|ncr_start
block|,
name|ncr_min_phys
block|,
literal|0
block|,
literal|0
block|,
name|ncr_info
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANCIENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|ncr_name
parameter_list|(
name|np
parameter_list|)
value|(np->sc_dev.dv_xname)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__NetBSD__ */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|ncr_name
parameter_list|(
name|ncb_p
name|np
parameter_list|)
block|{
specifier|static
name|char
name|name
index|[
literal|10
index|]
decl_stmt|;
name|sprintf
argument_list|(
name|name
argument_list|,
literal|"ncr%d"
argument_list|,
name|np
operator|->
name|unit
argument_list|)
expr_stmt|;
return|return
operator|(
name|name
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Scripts for NCR-Processor. ** **      Use ncr_script_bind for binding to physical addresses. ** ** **========================================================== ** **	NADDR generates a reference to a field of the controller data. **	PADDR generates a reference to another part of the script. **	RADDR generates a reference to a script processor register. **	FADDR generates a reference to a script processor register **		with offset. ** **---------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|RELOC_SOFTC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RELOC_LABEL
value|0x50000000
end_define

begin_define
define|#
directive|define
name|RELOC_REGISTER
value|0x60000000
end_define

begin_define
define|#
directive|define
name|RELOC_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|NADDR
parameter_list|(
name|label
parameter_list|)
value|(RELOC_SOFTC | offsetof(struct ncb, label))
end_define

begin_define
define|#
directive|define
name|PADDR
parameter_list|(
name|label
parameter_list|)
value|(RELOC_LABEL | offsetof(struct script, label))
end_define

begin_define
define|#
directive|define
name|RADDR
parameter_list|(
name|label
parameter_list|)
value|(RELOC_REGISTER | REG(label))
end_define

begin_define
define|#
directive|define
name|FADDR
parameter_list|(
name|label
parameter_list|,
name|ofs
parameter_list|)
value|(RELOC_REGISTER | ((REG(label))+(ofs)))
end_define

begin_decl_stmt
specifier|static
name|struct
name|script
name|script0
init|=
block|{
comment|/*--------------------------< START>-----------------------*/
block|{
comment|/* 	**	Claim to be still alive ... 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
operator|(
operator|(
expr|struct
name|ncb
operator|*
operator|)
literal|0
operator|)
operator|->
name|heartbeat
argument_list|)
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|time
operator|.
name|tv_sec
block|,
name|NADDR
argument_list|(
name|heartbeat
argument_list|)
block|,
comment|/* 	**      Make data structure address invalid. 	**      clear SIGP. 	*/
name|SCR_LOAD_REG
argument_list|(
name|dsa
argument_list|,
literal|0xff
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|ctest2
argument_list|)
block|,
literal|0
block|, }
comment|/*-------------------------< START0>----------------------*/
block|,
block|{
comment|/* 	**	Hook for interrupted GetConditionCode. 	**	Will be patched to ... IFTRUE by 	**	the interrupt handler. 	*/
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
literal|0
argument_list|)
block|,
name|SIR_SENSE_RESTART
block|,
block|}
comment|/*-------------------------< START1>----------------------*/
block|,
block|{
comment|/* 	**	Hook for stalled start queue. 	**	Will be patched to IFTRUE by the interrupt handler. 	*/
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
literal|0
argument_list|)
block|,
name|SIR_STALL_RESTART
block|,
comment|/* 	**	Then jump to a certain point in tryloop. 	**	Due to the lack of indirect addressing the code 	**	is self modifying here. 	*/
name|SCR_JUMP
block|, }
comment|/*-------------------------< STARTPOS>--------------------*/
block|,
block|{
name|PADDR
argument_list|(
name|tryloop
argument_list|)
block|, }
comment|/*-------------------------< TRYLOOP>---------------------*/
block|,
block|{
comment|/* **	Load an entry of the start queue into dsa **	and try to start it by jumping to TRYSEL. ** **	Because the size depends on the **	#define MAX_START parameter, it is filled **	in at runtime. ** **----------------------------------------------------------- ** **  ##===========< I=0; i<MAX_START>=========== **  ||	SCR_COPY (4), **  ||		NADDR (squeue[i]), **  ||		RADDR (dsa), **  ||	SCR_CALL, **  ||		PADDR (trysel), **  ##========================================== ** **	SCR_JUMP, **		PADDR(tryloop), ** **----------------------------------------------------------- */
literal|0
block|}
comment|/*-------------------------< TRYSEL>----------------------*/
block|,
block|{
comment|/* 	**	Now: 	**	DSA: Address of a Data Structure 	**	or   Address of the IDLE-Label. 	** 	**	TEMP:	Address of a script, which tries to 	**		start the NEXT entry. 	** 	**	Save the TEMP register into the SCRATCHA register. 	**	Then copy the DSA to TEMP and RETURN. 	**	This is kind of an indirect jump. 	**	(The script processor has NO stack, so the 	**	CALL is actually a jump and link, and the 	**	RETURN is an indirect jump.) 	** 	**	If the slot was empty, DSA contains the address 	**	of the IDLE part of this script. The processor 	**	jumps to IDLE and waits for a reselect. 	**	It will wake up and try the same slot again 	**	after the SIGP bit becomes set by the host. 	** 	**	If the slot was not empty, DSA contains 	**	the address of the phys-part of a ccb. 	**	The processor jumps to this address. 	**	phys starts with head, 	**	head starts with launch, 	**	so actually the processor jumps to 	**	the lauch part. 	**	If the entry is scheduled to be executed, 	**	then launch contains a jump to SELECT. 	**	If it's not scheduled, it contains a jump to IDLE. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|SCR_RETURN
block|,
literal|0
block|}
comment|/*-------------------------< SKIP>------------------------*/
block|,
block|{
comment|/* 	**	This entry has been canceled. 	**	Next time use the next slot. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|PADDR
argument_list|(
name|startpos
argument_list|)
block|,
comment|/* 	**	patch the launch field. 	**	should look like an idle process. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|PADDR
argument_list|(
name|skip2
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|8
argument_list|)
block|,
name|PADDR
argument_list|(
name|idle
argument_list|)
block|, }
comment|/*-------------------------< SKIP2>-----------------------*/
block|,
block|{
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|start
argument_list|)
block|, }
comment|/*-------------------------< IDLE>------------------------*/
block|,
block|{
comment|/* 	**	Nothing to do? 	**	Wait for reselect. 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|reselect
argument_list|)
block|,
block|}
comment|/*-------------------------< SELECT>----------------------*/
block|,
block|{
comment|/* 	**	DSA	contains the address of a scheduled 	**		data structure. 	** 	**	SCRATCHA contains the address of the script, 	**		which starts the next entry. 	** 	**	Set Initiator mode. 	** 	**	(Target mode is left as an exercise for the student) 	*/
name|SCR_CLR
argument_list|(
name|SCR_TRG
argument_list|)
block|,
literal|0
block|,
name|SCR_LOAD_REG
argument_list|(
name|HS_REG
argument_list|,
literal|0xff
argument_list|)
block|,
literal|0
block|,
comment|/* 	**      And try to select this target. 	*/
name|SCR_SEL_TBL_ATN
operator|^
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|select
argument_list|)
block|,
name|PADDR
argument_list|(
name|reselect
argument_list|)
block|,
comment|/* 	**	Now there are 4 possibilities: 	** 	**	(1) The ncr looses arbitration. 	**	This is ok, because it will try again, 	**	when the bus becomes idle. 	**	(But beware of the timeout function!) 	** 	**	(2) The ncr is reselected. 	**	Then the script processor takes the jump 	**	to the RESELECT label. 	** 	**	(3) The ncr completes the selection. 	**	Then it will execute the next statement. 	** 	**	(4) There is a selection timeout. 	**	Then the ncr should interrupt the host and stop. 	**	Unfortunately, it seems to continue execution 	**	of the script. But it will fail with an 	**	IID-interrupt on the next WHEN. 	*/
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Save target id to ctest0 register 	*/
name|SCR_FROM_REG
argument_list|(
name|sdid
argument_list|)
block|,
literal|0
block|,
name|SCR_TO_REG
argument_list|(
name|ctest0
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Send the IDENTIFY and SIMPLE_TAG messages 	**	(and the M_X_SYNC_REQ message) 	*/
name|SCR_MOVE_TBL
operator|^
name|SCR_MSG_OUT
block|,
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|smsg
argument_list|)
block|,
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_OUT
argument_list|)
argument_list|)
block|,
operator|-
literal|16
block|,
name|SCR_CLR
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
comment|/* 	**	Selection complete. 	**	Next time use the next slot. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|PADDR
argument_list|(
name|startpos
argument_list|)
block|, }
comment|/*-------------------------< PREPARE>----------------------*/
block|,
block|{
comment|/* 	**      The ncr doesn't have an indirect load 	**	or store command. So we have to 	**	copy part of the control block to a 	**	fixed place, where we can access it. 	** 	**	We patch the address part of a 	**	COPY command with the DSA-register. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|PADDR
argument_list|(
name|loadpos
argument_list|)
block|,
comment|/* 	**	then we do the actual copy. 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|head
argument_list|)
argument_list|)
block|,
comment|/* 	**	continued after the next label ... 	*/
block|}
comment|/*-------------------------< LOADPOS>---------------------*/
block|,
block|{
literal|0
block|,
name|NADDR
argument_list|(
name|header
argument_list|)
block|,
comment|/* 	**      Mark this ccb as not scheduled. 	*/
name|SCR_COPY
argument_list|(
literal|8
argument_list|)
block|,
name|PADDR
argument_list|(
name|idle
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|launch
argument_list|)
block|,
comment|/* 	**      Set a time stamp for this selection 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|time
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|select
argument_list|)
block|,
comment|/* 	**      load the savep (saved pointer) into 	**      the TEMP register (actual pointer) 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
comment|/* 	**      Initialize the status registers 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|status
argument_list|)
block|,
name|RADDR
argument_list|(
name|scr0
argument_list|)
block|,
block|}
comment|/*-------------------------< PREPARE2>---------------------*/
block|,
block|{
comment|/* 	**      Load the synchronous mode register 	*/
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|NADDR
argument_list|(
name|sync_st
argument_list|)
block|,
name|RADDR
argument_list|(
name|sxfer
argument_list|)
block|,
comment|/* 	**      Load the wide mode and timing register 	*/
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|NADDR
argument_list|(
name|wide_st
argument_list|)
block|,
name|RADDR
argument_list|(
name|scntl3
argument_list|)
block|,
comment|/* 	**	Initialize the msgout buffer with a NOOP message. 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_NOOP
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|msgin
argument_list|)
block|,
comment|/* 	**	Message in phase ? 	*/
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	Extended or reject message ? 	*/
name|SCR_FROM_REG
argument_list|(
name|sbdl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_EXTENDED
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_in
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_REJECT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_reject
argument_list|)
block|,
comment|/* 	**	normal processing 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|, }
comment|/*-------------------------< SETMSG>----------------------*/
block|,
block|{
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_SET
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|, }
comment|/*-------------------------< CLRACK>----------------------*/
block|,
block|{
comment|/* 	**	Terminate possible pending message phase. 	*/
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
block|}
comment|/*-----------------------< DISPATCH>----------------------*/
block|,
block|{
name|SCR_FROM_REG
argument_list|(
name|HS_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_INT
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|HS_NEGOTIATE
argument_list|)
argument_list|)
block|,
name|SIR_NEGO_FAILED
block|,
name|SCR_RETURN
operator|^
name|IFTRUE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_OUT
argument_list|)
argument_list|)
block|,
literal|0
block|,
name|SCR_RETURN
operator|^
name|IFTRUE
argument_list|(
name|IF
argument_list|(
name|SCR_DATA_IN
argument_list|)
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|IF
argument_list|(
name|SCR_MSG_OUT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_out
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|IF
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_in
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|IF
argument_list|(
name|SCR_COMMAND
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|command
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|IF
argument_list|(
name|SCR_STATUS
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|status
argument_list|)
block|,
comment|/* 	**      Discard one illegal phase byte, if required. 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|XE_BAD_PHASE
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|xerr_st
argument_list|)
block|,
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|IF
argument_list|(
name|SCR_ILG_OUT
argument_list|)
argument_list|)
block|,
literal|8
block|,
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_ILG_OUT
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|IF
argument_list|(
name|SCR_ILG_IN
argument_list|)
argument_list|)
block|,
literal|8
block|,
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_ILG_IN
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
block|}
comment|/*-------------------------< NO_DATA>--------------------*/
block|,
block|{
comment|/* 	**	The target wants to tranfer too much data 	**	or in the wrong direction. 	**      Remember that in extended error. 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|XE_EXTRA_DATA
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|xerr_st
argument_list|)
block|,
comment|/* 	**      Discard one data byte, if required. 	*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_OUT
argument_list|)
argument_list|)
block|,
literal|8
block|,
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_DATA_OUT
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|IF
argument_list|(
name|SCR_DATA_IN
argument_list|)
argument_list|)
block|,
literal|8
block|,
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_DATA_IN
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
comment|/* 	**      .. and repeat as required. 	*/
name|SCR_CALL
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|no_data
argument_list|)
block|, }
comment|/*-------------------------< CHECKATN>--------------------*/
block|,
block|{
comment|/* 	**	If AAP (bit 1 of scntl0 register) is set 	**	and a parity error is detected, 	**	the script processor asserts ATN. 	** 	**	The target should switch to a MSG_OUT phase 	**	to get the message. 	*/
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	count it 	*/
name|SCR_REG_REG
argument_list|(
name|PS_REG
argument_list|,
name|SCR_ADD
argument_list|,
literal|1
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Prepare a M_ID_ERROR message 	**	(initiator detected error). 	**	The target should retry the transfer. 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_ID_ERROR
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|setmsg
argument_list|)
block|,
block|}
comment|/*-------------------------< COMMAND>--------------------*/
block|,
block|{
comment|/* 	**	If this is not a GETCC transfer ... 	*/
name|SCR_FROM_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|S_CHECK_COND
argument_list|)
argument_list|)
block|,
literal|28
block|,
comment|/* 	**	... set a timestamp ... 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|time
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|command
argument_list|)
block|,
comment|/* 	**	... and send the command 	*/
name|SCR_MOVE_TBL
operator|^
name|SCR_COMMAND
block|,
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|cmd
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	Send the GETCC command 	*/
comment|/*>>>*/
name|SCR_MOVE_ABS
argument_list|(
literal|6
argument_list|)
operator|^
name|SCR_COMMAND
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|rs_cmd
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
block|}
comment|/*-------------------------< STATUS>--------------------*/
block|,
block|{
comment|/* 	**	set the timestamp. 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|time
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|status
argument_list|)
block|,
comment|/* 	**	If this is a GETCC transfer, 	*/
name|SCR_FROM_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
name|S_CHECK_COND
argument_list|)
argument_list|)
block|,
literal|40
block|,
comment|/* 	**	get the status 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_STATUS
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
comment|/* 	**	Save status to scsi_status. 	**	Mark as complete. 	**	And wait for disconnect. 	*/
name|SCR_TO_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_REG_REG
argument_list|(
name|SS_REG
argument_list|,
name|SCR_OR
argument_list|,
name|S_SENSE
argument_list|)
block|,
literal|0
block|,
name|SCR_LOAD_REG
argument_list|(
name|HS_REG
argument_list|,
name|HS_COMPLETE
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|checkatn
argument_list|)
block|,
comment|/* 	**	If it was no GETCC transfer, 	**	save the status to scsi_status. 	*/
comment|/*>>>*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_STATUS
block|,
name|NADDR
argument_list|(
name|scratch
argument_list|)
block|,
name|SCR_TO_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	if it was no check condition ... 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|S_CHECK_COND
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|checkatn
argument_list|)
block|,
comment|/* 	**	... mark as complete. 	*/
name|SCR_LOAD_REG
argument_list|(
name|HS_REG
argument_list|,
name|HS_COMPLETE
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|checkatn
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_IN>--------------------*/
block|,
block|{
comment|/* 	**	Get the first byte of the message 	**	and save it to SCRATCHA. 	** 	**	The script processor doesn't negate the 	**	ACK signal after this transfer. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|0
index|]
argument_list|)
block|,
comment|/* 	**	Check for message parity error. 	*/
name|SCR_TO_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Parity was ok, handle this message. 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_COMPLETE
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|complete
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_SAVE_DP
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|save_dp
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_RESTORE_DP
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|restore_dp
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_DISCONNECT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|disconnect
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_EXTENDED
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_extended
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_NOOP
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_REJECT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_reject
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_IGN_RESIDUE
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_ign_residue
argument_list|)
block|,
comment|/* 	**	Rest of the messages left as 	**	an exercise ... 	** 	**	Unimplemented messages: 	**	fall through to MSG_BAD. 	*/
block|}
comment|/*-------------------------< MSG_BAD>------------------*/
block|,
block|{
comment|/* 	**	unimplemented message - reject it. 	*/
name|SCR_INT
block|,
name|SIR_REJECT_SENT
block|,
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_REJECT
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|setmsg
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_PARITY>---------------*/
block|,
block|{
comment|/* 	**	count it 	*/
name|SCR_REG_REG
argument_list|(
name|PS_REG
argument_list|,
name|SCR_ADD
argument_list|,
literal|0x01
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	send a "message parity error" message. 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_PARITY
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|setmsg
argument_list|)
block|, }
comment|/*-------------------------< MSG_REJECT>---------------*/
block|,
block|{
comment|/* 	**	If a negotiation was in progress, 	**	negotiation failed. 	*/
name|SCR_FROM_REG
argument_list|(
name|HS_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_INT
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|HS_NEGOTIATE
argument_list|)
argument_list|)
block|,
name|SIR_NEGO_FAILED
block|,
comment|/* 	**	else make host log this message 	*/
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
name|HS_NEGOTIATE
argument_list|)
argument_list|)
block|,
name|SIR_REJECT_RECEIVED
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_IGN_RESIDUE>----------*/
block|,
block|{
comment|/* 	**	Terminate cycle 	*/
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get residue size. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|1
index|]
argument_list|)
block|,
comment|/* 	**	Check for message parity error. 	*/
name|SCR_TO_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Size is 0 .. ignore message. 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
literal|0
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
comment|/* 	**	Size is not 1 .. have to interrupt. 	*/
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
literal|1
argument_list|)
argument_list|)
block|,
literal|40
block|,
comment|/* 	**	Check for residue byte in swide register 	*/
name|SCR_FROM_REG
argument_list|(
name|scntl2
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
name|WSR
argument_list|,
name|WSR
argument_list|)
argument_list|)
block|,
literal|16
block|,
comment|/* 	**	There IS data in the swide register. 	**	Discard it. 	*/
name|SCR_REG_REG
argument_list|(
name|scntl2
argument_list|,
name|SCR_OR
argument_list|,
name|WSR
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
comment|/* 	**	Load again the size to the sfbr register. 	*/
comment|/*>>>*/
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
comment|/*>>>*/
name|SCR_INT
block|,
name|SIR_IGN_RESIDUE
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_EXTENDED>-------------*/
block|,
block|{
comment|/* 	**	Terminate cycle 	*/
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get length. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|1
index|]
argument_list|)
block|,
comment|/* 	**	Check for message parity error. 	*/
name|SCR_TO_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
comment|/* 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
literal|3
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_ext_3
argument_list|)
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
literal|2
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_bad
argument_list|)
block|, }
comment|/*-------------------------< MSG_EXT_2>----------------*/
block|,
block|{
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get extended message code. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|2
index|]
argument_list|)
block|,
comment|/* 	**	Check for message parity error. 	*/
name|SCR_TO_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_X_WIDE_REQ
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_wdtr
argument_list|)
block|,
comment|/* 	**	unknown extended message 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
argument|msg_bad
argument_list|)
block|}
comment|/*-------------------------< MSG_WDTR>-----------------*/
block|,
block|{
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get data bus width 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|3
index|]
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
comment|/* 	**	let the host do the real work. 	*/
name|SCR_INT
block|,
name|SIR_NEGO_WIDE
block|,
comment|/* 	**	let the target fetch our answer. 	*/
name|SCR_SET
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_OUT
argument_list|)
argument_list|)
block|,
name|SIR_NEGO_PROTO
block|,
comment|/* 	**	Send the M_X_WIDE_REQ 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|4
argument_list|)
operator|^
name|SCR_MSG_OUT
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|msg_out_done
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_EXT_3>----------------*/
block|,
block|{
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get extended message code. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|2
index|]
argument_list|)
block|,
comment|/* 	**	Check for message parity error. 	*/
name|SCR_TO_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|scratcha
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_X_SYNC_REQ
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_sdtr
argument_list|)
block|,
comment|/* 	**	unknown extended message 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
argument|msg_bad
argument_list|)
block|}
comment|/*-------------------------< MSG_SDTR>-----------------*/
block|,
block|{
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|,
comment|/* 	**	get period and offset 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|2
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
index|[
literal|3
index|]
argument_list|)
block|,
name|SCR_FROM_REG
argument_list|(
name|socl
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CATN
argument_list|,
name|CATN
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_parity
argument_list|)
block|,
comment|/* 	**	let the host do the real work. 	*/
name|SCR_INT
block|,
name|SIR_NEGO_SYNC
block|,
comment|/* 	**	let the target fetch our answer. 	*/
name|SCR_SET
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_OUT
argument_list|)
argument_list|)
block|,
name|SIR_NEGO_PROTO
block|,
comment|/* 	**	Send the M_X_SYNC_REQ 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|5
argument_list|)
operator|^
name|SCR_MSG_OUT
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|msg_out_done
argument_list|)
block|,
block|}
comment|/*-------------------------< COMPLETE>-----------------*/
block|,
block|{
comment|/* 	**	Complete message. 	** 	**	If it's not the get condition code, 	**	copy TEMP register to LASTP in header. 	*/
name|SCR_FROM_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|S_SENSE
argument_list|,
name|S_SENSE
argument_list|)
argument_list|)
block|,
literal|12
block|,
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|lastp
argument_list|)
block|,
comment|/*>>>*/
comment|/* 	**	When we terminate the cycle by clearing ACK, 	**	the target may disconnect immediately. 	** 	**	We don't want to be told of an 	**	"unexpected disconnect", 	**	so we disable this feature. 	*/
name|SCR_REG_REG
argument_list|(
name|scntl2
argument_list|,
name|SCR_AND
argument_list|,
literal|0x7f
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Terminate cycle ... 	*/
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	... and wait for the disconnect. 	*/
name|SCR_WAIT_DISC
block|,
literal|0
block|, }
comment|/*-------------------------< CLEANUP>-------------------*/
block|,
block|{
comment|/* 	**      dsa:    Pointer to ccb 	**              or xxxxxxFF (no ccb) 	** 	**      HS_REG:   Host-Status (<>0!) 	*/
name|SCR_FROM_REG
argument_list|(
name|dsa
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
literal|0xff
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|signal
argument_list|)
block|,
comment|/* 	**      dsa is valid. 	**	save the status registers 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|scr0
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|status
argument_list|)
block|,
comment|/* 	**	and copy back the header to the ccb. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|PADDR
argument_list|(
name|cleanup0
argument_list|)
block|,
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|head
argument_list|)
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
argument_list|)
block|, }
comment|/*-------------------------< CLEANUP0>--------------------*/
block|,
block|{
literal|0
block|,
comment|/* 	**	If command resulted in "check condition" 	**	status and is not yet completed, 	**	try to get the condition code. 	*/
name|SCR_FROM_REG
argument_list|(
name|HS_REG
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
literal|0
argument_list|,
name|HS_DONEMASK
argument_list|)
argument_list|)
block|,
literal|16
block|,
name|SCR_FROM_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|S_CHECK_COND
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|getcc2
argument_list|)
block|,
comment|/* 	**	And make the DSA register invalid. 	*/
comment|/*>>>*/
name|SCR_LOAD_REG
argument_list|(
name|dsa
argument_list|,
literal|0xff
argument_list|)
block|,
comment|/* invalid */
literal|0
block|, }
comment|/*-------------------------< SIGNAL>----------------------*/
block|,
block|{
comment|/* 	**	if status = queue full, 	**	reinsert in startqueue and stall queue. 	*/
name|SCR_FROM_REG
argument_list|(
name|SS_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_INT
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|S_QUEUE_FULL
argument_list|)
argument_list|)
block|,
name|SIR_STALL_QUEUE
block|,
comment|/* 	**	if job completed ... 	*/
name|SCR_FROM_REG
argument_list|(
name|HS_REG
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	... signal completion to the host 	*/
name|SCR_INT_FLY
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
literal|0
argument_list|,
name|HS_DONEMASK
argument_list|)
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Auf zu neuen Schandtaten! 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|start
argument_list|)
block|,
block|}
comment|/*-------------------------< SAVE_DP>------------------*/
block|,
block|{
comment|/* 	**	SAVE_DP message: 	**	Copy TEMP register to SAVEP in header. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|, }
comment|/*-------------------------< RESTORE_DP>---------------*/
block|,
block|{
comment|/* 	**	RESTORE_DP message: 	**	Copy SAVEP in header to TEMP register. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|clrack
argument_list|)
block|,
block|}
comment|/*-------------------------< DISCONNECT>---------------*/
block|,
block|{
comment|/* 	**	If QUIRK_AUTOSAVE is set, 	**	do an "save pointer" operation. 	*/
name|SCR_FROM_REG
argument_list|(
name|QU_REG
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
name|QUIRK_AUTOSAVE
argument_list|,
name|QUIRK_AUTOSAVE
argument_list|)
argument_list|)
block|,
literal|12
block|,
comment|/* 	**	like SAVE_DP message: 	**	Copy TEMP register to SAVEP in header. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
comment|/*>>>*/
comment|/* 	**	Check if temp==savep or temp==goalp: 	**	if not, log a missing save pointer message. 	**	In fact, it's a comparation mod 256. 	** 	**	Hmmm, I hadn't thought that I would be urged to 	**	write this kind of ugly self modifying code. 	** 	**	It's unbelievable, but the ncr53c8xx isn't able 	**	to subtract one register from another. 	*/
name|SCR_FROM_REG
argument_list|(
name|temp
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	You are not expected to understand this .. 	*/
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
name|PADDR
argument_list|(
name|disconnect0
argument_list|)
block|, }
comment|/*-------------------------< DISCONNECT0>--------------*/
block|,
block|{
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
literal|1
argument_list|)
argument_list|)
block|,
literal|20
block|,
comment|/* 	**	neither this 	*/
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|goalp
argument_list|)
block|,
name|PADDR
argument_list|(
name|disconnect1
argument_list|)
block|, }
comment|/*-------------------------< DISCONNECT1>--------------*/
block|,
block|{
name|SCR_INT
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
literal|1
argument_list|)
argument_list|)
block|,
name|SIR_MISSING_SAVE
block|,
comment|/*>>>*/
comment|/* 	**	DISCONNECTing  ... 	** 	**	disable the "unexpected disconnect" feature, 	**	and remove the ACK signal. 	*/
name|SCR_REG_REG
argument_list|(
name|scntl2
argument_list|,
name|SCR_AND
argument_list|,
literal|0x7f
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Wait for the disconnect. 	*/
name|SCR_WAIT_DISC
block|,
literal|0
block|,
comment|/* 	**	Profiling: 	**	Set a time stamp, 	**	and count the disconnects. 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|time
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|disconnect
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|NADDR
argument_list|(
name|disc_phys
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|SCR_REG_REG
argument_list|(
name|temp
argument_list|,
name|SCR_ADD
argument_list|,
literal|0x01
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|NADDR
argument_list|(
name|disc_phys
argument_list|)
block|,
comment|/* 	**	Status is: DISCONNECTED. 	*/
name|SCR_LOAD_REG
argument_list|(
name|HS_REG
argument_list|,
name|HS_DISCONNECT
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|cleanup
argument_list|)
block|,
block|}
comment|/*-------------------------< MSG_OUT>-------------------*/
block|,
block|{
comment|/* 	**	The target requests a message. 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_OUT
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
comment|/* 	**	If it was no ABORT message ... 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|DATA
argument_list|(
name|M_ABORT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_out_abort
argument_list|)
block|,
comment|/* 	**	... wait for the next phase 	**	if it's a message out, send it again, ... 	*/
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_OUT
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|msg_out
argument_list|)
block|, }
comment|/*-------------------------< MSG_OUT_DONE>--------------*/
block|,
block|{
comment|/* 	**	... else clear the message ... 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_NOOP
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
comment|/* 	**	... and process the next phase 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|dispatch
argument_list|)
block|, }
comment|/*-------------------------< MSG_OUT_ABORT>-------------*/
block|,
block|{
comment|/* 	**	After ABORT message, 	** 	**	expect an immediate disconnect, ... 	*/
name|SCR_REG_REG
argument_list|(
name|scntl2
argument_list|,
name|SCR_AND
argument_list|,
literal|0x7f
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_WAIT_DISC
block|,
literal|0
block|,
comment|/* 	**	... and set the status to "ABORTED" 	*/
name|SCR_LOAD_REG
argument_list|(
name|HS_REG
argument_list|,
name|HS_ABORTED
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|cleanup
argument_list|)
block|,
block|}
comment|/*-------------------------< GETCC>-----------------------*/
block|,
block|{
comment|/* 	**	The ncr doesn't have an indirect load 	**	or store command. So we have to 	**	copy part of the control block to a 	**	fixed place, where we can modify it. 	** 	**	We patch the address part of a COPY command 	**	with the address of the dsa register ... 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|PADDR
argument_list|(
name|getcc1
argument_list|)
block|,
comment|/* 	**	... then we do the actual copy. 	*/
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|head
argument_list|)
argument_list|)
block|, }
comment|/*-------------------------< GETCC1>----------------------*/
block|,
block|{
literal|0
block|,
name|NADDR
argument_list|(
name|header
argument_list|)
block|,
comment|/* 	**	Initialize the status registers 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|status
argument_list|)
block|,
name|RADDR
argument_list|(
name|scr0
argument_list|)
block|, }
comment|/*-------------------------< GETCC2>----------------------*/
block|,
block|{
comment|/* 	**	Get the condition code from a target. 	** 	**	DSA points to a data structure. 	**	Set TEMP to the script location 	**	that receives the condition code. 	** 	**	Because there is no script command 	**	to load a longword into a register, 	**	we use a CALL command. 	*/
comment|/*<<<*/
name|SCR_CALLR
block|,
literal|24
block|,
comment|/* 	**	Get the condition code. 	*/
name|SCR_MOVE_TBL
operator|^
name|SCR_DATA_IN
block|,
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|sense
argument_list|)
block|,
comment|/* 	**	No data phase may follow! 	*/
name|SCR_CALL
block|,
name|PADDR
argument_list|(
name|checkatn
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|no_data
argument_list|)
block|,
comment|/*>>>*/
comment|/* 	**	The CALL jumps to this point. 	**	Prepare for a RESTORE_POINTER message. 	**	Save the TEMP register into the saved pointer. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|NADDR
argument_list|(
name|header
operator|.
name|savep
argument_list|)
block|,
comment|/* 	**	Load scratcha, because in case of a selection timeout, 	**	the host will expect a new value for startpos in 	**	the scratcha register. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|PADDR
argument_list|(
name|startpos
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
comment|/* 	**	If QUIRK_NOMSG is set, select without ATN. 	**	and don't send a message. 	*/
name|SCR_FROM_REG
argument_list|(
name|QU_REG
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|QUIRK_NOMSG
argument_list|,
name|QUIRK_NOMSG
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|getcc3
argument_list|)
block|,
comment|/* 	**	Then try to connect to the target. 	**	If we are reselected, special treatment 	**	of the current job is required before 	**	accepting the reselection. 	*/
name|SCR_SEL_TBL_ATN
operator|^
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|select
argument_list|)
block|,
name|PADDR
argument_list|(
name|badgetcc
argument_list|)
block|,
comment|/* 	**	save target id. 	*/
name|SCR_FROM_REG
argument_list|(
name|sdid
argument_list|)
block|,
literal|0
block|,
name|SCR_TO_REG
argument_list|(
name|ctest0
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Send the IDENTIFY message. 	**	In case of short transfer, remove ATN. 	*/
name|SCR_MOVE_TBL
operator|^
name|SCR_MSG_OUT
block|,
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|smsg2
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	save the first byte of the message. 	*/
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|prepare2
argument_list|)
block|,
block|}
comment|/*-------------------------< GETCC3>----------------------*/
block|,
block|{
comment|/* 	**	Try to connect to the target. 	**	If we are reselected, special treatment 	**	of the current job is required before 	**	accepting the reselection. 	** 	**	Silly target won't accept a message. 	**	Select without ATN. 	*/
name|SCR_SEL_TBL
operator|^
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|select
argument_list|)
block|,
name|PADDR
argument_list|(
name|badgetcc
argument_list|)
block|,
comment|/* 	**	save target id. 	*/
name|SCR_FROM_REG
argument_list|(
name|sdid
argument_list|)
block|,
literal|0
block|,
name|SCR_TO_REG
argument_list|(
name|ctest0
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Force error if selection timeout 	*/
name|SCR_JUMPR
operator|^
name|IFTRUE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	don't negotiate. 	*/
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|prepare2
argument_list|)
block|,
block|}
comment|/*------------------------< BADGETCC>---------------------*/
block|,
block|{
comment|/* 	**	If SIGP was set, clear it and try again. 	*/
name|SCR_FROM_REG
argument_list|(
name|ctest2
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CSIGP
argument_list|,
name|CSIGP
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|getcc2
argument_list|)
block|,
name|SCR_INT
block|,
name|SIR_SENSE_FAILED
block|, }
comment|/*-------------------------< RESELECT>--------------------*/
block|,
block|{
comment|/* 	**	make the DSA invalid. 	*/
name|SCR_LOAD_REG
argument_list|(
name|dsa
argument_list|,
literal|0xff
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_TRG
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Sleep waiting for a reselection. 	**	If SIGP is set, special treatment. 	** 	**	Zu allem bereit .. 	*/
name|SCR_WAIT_RESEL
block|,
name|PADDR
argument_list|(
name|reselect2
argument_list|)
block|,
comment|/* 	**	... zu nichts zu gebrauchen ? 	** 	**      load the target id into the SFBR 	**	and jump to the control block. 	** 	**	Look at the declarations of 	**	- struct ncb 	**	- struct tcb 	**	- struct lcb 	**	- struct ccb 	**	to understand what's going on. 	*/
name|SCR_REG_SFBR
argument_list|(
name|ssid
argument_list|,
name|SCR_AND
argument_list|,
literal|0x87
argument_list|)
block|,
literal|0
block|,
name|SCR_TO_REG
argument_list|(
name|ctest0
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|NADDR
argument_list|(
name|jump_tcb
argument_list|)
block|, }
comment|/*-------------------------< RESELECT2>-------------------*/
block|,
block|{
comment|/* 	**	If it's not connected :( 	**	-> interrupted by SIGP bit. 	**	Jump to start. 	*/
name|SCR_FROM_REG
argument_list|(
name|ctest2
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMP
operator|^
name|IFTRUE
argument_list|(
name|MASK
argument_list|(
name|CSIGP
argument_list|,
name|CSIGP
argument_list|)
argument_list|)
block|,
name|PADDR
argument_list|(
name|start
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|reselect
argument_list|)
block|,
block|}
comment|/*-------------------------< RESEL_TMP>-------------------*/
block|,
block|{
comment|/* 	**	The return address in TEMP 	**	is in fact the data structure address, 	**	so copy it to the DSA register. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
name|RADDR
argument_list|(
name|dsa
argument_list|)
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|prepare
argument_list|)
block|,  }
comment|/*-------------------------< RESEL_LUN>-------------------*/
block|,
block|{
comment|/* 	**	come back to this point 	**	to get an IDENTIFY message 	**	Wait for a msg_in phase. 	*/
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
literal|48
block|,
comment|/* 	**	message phase 	**	It's not a sony, it's a trick: 	**	read the data without acknowledging it. 	*/
name|SCR_FROM_REG
argument_list|(
name|sbdl
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|MASK
argument_list|(
name|M_IDENTIFY
argument_list|,
literal|0x98
argument_list|)
argument_list|)
block|,
literal|32
block|,
comment|/* 	**	It WAS an Identify message. 	**	get it and ack it! 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Mask out the LUN. 	*/
name|SCR_REG_REG
argument_list|(
name|sfbr
argument_list|,
name|SCR_AND
argument_list|,
literal|0x07
argument_list|)
block|,
literal|0
block|,
name|SCR_RETURN
block|,
literal|0
block|,
comment|/* 	**	No message phase or no IDENTIFY message: 	**	return 0. 	*/
comment|/*>>>*/
name|SCR_LOAD_SFBR
argument_list|(
literal|0
argument_list|)
block|,
literal|0
block|,
name|SCR_RETURN
block|,
literal|0
block|,
block|}
comment|/*-------------------------< RESEL_TAG>-------------------*/
block|,
block|{
comment|/* 	**	come back to this point 	**	to get a SIMPLE_TAG message 	**	Wait for a MSG_IN phase. 	*/
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
literal|64
block|,
comment|/* 	**	message phase 	**	It's a trick - read the data 	**	without acknowledging it. 	*/
name|SCR_FROM_REG
argument_list|(
name|sbdl
argument_list|)
block|,
literal|0
block|,
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|DATA
argument_list|(
name|M_SIMPLE_TAG
argument_list|)
argument_list|)
block|,
literal|48
block|,
comment|/* 	**	It WAS a SIMPLE_TAG message. 	**	get it and ack it! 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	Wait for the second byte (the tag) 	*/
comment|/*<<<*/
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_MSG_IN
argument_list|)
argument_list|)
block|,
literal|24
block|,
comment|/* 	**	Get it and ack it! 	*/
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_IN
block|,
name|NADDR
argument_list|(
name|msgin
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
operator||
name|SCR_CARRY
argument_list|)
block|,
literal|0
block|,
name|SCR_RETURN
block|,
literal|0
block|,
comment|/* 	**	No message phase or no SIMPLE_TAG message 	**	or no second byte: return 0. 	*/
comment|/*>>>*/
name|SCR_LOAD_SFBR
argument_list|(
literal|0
argument_list|)
block|,
literal|0
block|,
name|SCR_SET
argument_list|(
name|SCR_CARRY
argument_list|)
block|,
literal|0
block|,
name|SCR_RETURN
block|,
literal|0
block|,
block|}
comment|/*-------------------------< DATA_IN>--------------------*/
block|,
block|{
comment|/* **	Because the size depends on the **	#define MAX_SCATTER parameter, **	it is filled in at runtime. ** **	SCR_JUMP ^ IFFALSE (WHEN (SCR_DATA_IN)), **		PADDR (no_data), **	SCR_COPY (sizeof (struct timeval)), **		(ncrcmd)&time, **		NADDR (header.stamp.data), **	SCR_MOVE_TBL ^ SCR_DATA_IN, **		offsetof (struct dsb, data[ 0]), ** **  ##===========< i=1; i<MAX_SCATTER>========= **  ||	SCR_CALL ^ IFFALSE (WHEN (SCR_DATA_IN)), **  ||		PADDR (checkatn), **  ||	SCR_MOVE_TBL ^ SCR_DATA_IN, **  ||		offsetof (struct dsb, data[ i]), **  ##========================================== ** **	SCR_CALL, **		PADDR (checkatn), **	SCR_JUMP, **		PADDR (no_data), */
literal|0
block|}
comment|/*-------------------------< DATA_OUT>-------------------*/
block|,
block|{
comment|/* **	Because the size depends on the **	#define MAX_SCATTER parameter, **	it is filled in at runtime. ** **	SCR_JUMP ^ IFFALSE (WHEN (SCR_DATA_IN)), **		PADDR (no_data), **	SCR_COPY (sizeof (struct timeval)), **		(ncrcmd)&time, **		NADDR (header.stamp.data), **	SCR_MOVE_TBL ^ SCR_DATA_OUT, **		offsetof (struct dsb, data[ 0]), ** **  ##===========< i=1; i<MAX_SCATTER>========= **  ||	SCR_CALL ^ IFFALSE (WHEN (SCR_DATA_OUT)), **  ||		PADDR (dispatch), **  ||	SCR_MOVE_TBL ^ SCR_DATA_OUT, **  ||		offsetof (struct dsb, data[ i]), **  ##========================================== ** **	SCR_CALL, **		PADDR (dispatch), **	SCR_JUMP, **		PADDR (no_data), ** **--------------------------------------------------------- */
operator|(
name|u_long
operator|)
operator|&
name|ident
block|}
comment|/*-------------------------< ABORTTAG>-------------------*/
block|,
block|{
comment|/* 	**      Abort a bad reselection. 	**	Set the message to ABORT vs. ABORT_TAG 	*/
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_ABORT_TAG
argument_list|)
block|,
literal|0
block|,
name|SCR_JUMPR
operator|^
name|IFFALSE
argument_list|(
name|CARRYSET
argument_list|)
block|,
literal|8
block|, }
comment|/*-------------------------< ABORT>----------------------*/
block|,
block|{
name|SCR_LOAD_REG
argument_list|(
name|scratcha
argument_list|,
name|M_ABORT
argument_list|)
block|,
literal|0
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_SET
argument_list|(
name|SCR_ATN
argument_list|)
block|,
literal|0
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
comment|/* 	**	and send it. 	**	we expect an immediate disconnect 	*/
name|SCR_REG_REG
argument_list|(
name|scntl2
argument_list|,
name|SCR_AND
argument_list|,
literal|0x7f
argument_list|)
block|,
literal|0
block|,
name|SCR_MOVE_ABS
argument_list|(
literal|1
argument_list|)
operator|^
name|SCR_MSG_OUT
block|,
name|NADDR
argument_list|(
name|msgout
argument_list|)
block|,
name|SCR_COPY
argument_list|(
literal|1
argument_list|)
block|,
name|RADDR
argument_list|(
name|sfbr
argument_list|)
block|,
name|NADDR
argument_list|(
name|lastmsg
argument_list|)
block|,
name|SCR_CLR
argument_list|(
name|SCR_ACK
argument_list|)
block|,
literal|0
block|,
name|SCR_WAIT_DISC
block|,
literal|0
block|,
name|SCR_JUMP
block|,
name|PADDR
argument_list|(
name|start
argument_list|)
block|, }
comment|/*-------------------------< SNOOPTEST>-------------------*/
block|,
block|{
comment|/* 	**	Read the variable. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|ncr_cache
block|,
name|RADDR
argument_list|(
name|scratcha
argument_list|)
block|,
comment|/* 	**	Write the variable. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|ncr_cache
block|,
comment|/* 	**	Read back the variable. 	*/
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
block|,
operator|(
name|ncrcmd
operator|)
operator|&
name|ncr_cache
block|,
name|RADDR
argument_list|(
name|temp
argument_list|)
block|,
comment|/* 	**	And stop. 	*/
name|SCR_INT
block|,
literal|99
block|, }
comment|/*--------------------------------------------------------*/
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **	Fill in #define dependent parts of the script ** ** **========================================================== */
end_comment

begin_function
name|void
name|ncr_script_fill
parameter_list|(
name|struct
name|script
modifier|*
name|scr
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|ncrcmd
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|scr
operator|->
name|tryloop
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|MAX_START
condition|;
name|i
operator|++
control|)
block|{
operator|*
name|p
operator|++
operator|=
name|SCR_COPY
argument_list|(
literal|4
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|NADDR
argument_list|(
name|squeue
index|[
name|i
index|]
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|RADDR
argument_list|(
name|dsa
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_CALL
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|trysel
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_JUMP
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|tryloop
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|u_long
operator|)
name|p
operator|==
operator|(
name|u_long
operator|)
operator|&
name|scr
operator|->
name|tryloop
operator|+
sizeof|sizeof
argument_list|(
name|scr
operator|->
name|tryloop
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|=
name|scr
operator|->
name|data_in
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_IN
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|no_data
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
operator|(
name|ncrcmd
operator|)
operator|&
name|time
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|data
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_MOVE_TBL
operator|^
name|SCR_DATA_IN
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|MAX_SCATTER
condition|;
name|i
operator|++
control|)
block|{
operator|*
name|p
operator|++
operator|=
name|SCR_CALL
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_IN
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|checkatn
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_MOVE_TBL
operator|^
name|SCR_DATA_IN
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_CALL
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|checkatn
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_JUMP
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|no_data
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|u_long
operator|)
name|p
operator|==
operator|(
name|u_long
operator|)
operator|&
name|scr
operator|->
name|data_in
operator|+
sizeof|sizeof
argument_list|(
name|scr
operator|->
name|data_in
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|=
name|scr
operator|->
name|data_out
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_JUMP
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_OUT
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|no_data
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_COPY
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
operator|(
name|ncrcmd
operator|)
operator|&
name|time
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|NADDR
argument_list|(
name|header
operator|.
name|stamp
operator|.
name|data
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_MOVE_TBL
operator|^
name|SCR_DATA_OUT
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|MAX_SCATTER
condition|;
name|i
operator|++
control|)
block|{
operator|*
name|p
operator|++
operator|=
name|SCR_CALL
operator|^
name|IFFALSE
argument_list|(
name|WHEN
argument_list|(
name|SCR_DATA_OUT
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|dispatch
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_MOVE_TBL
operator|^
name|SCR_DATA_OUT
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|offsetof
argument_list|(
expr|struct
name|dsb
argument_list|,
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_CALL
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|dispatch
argument_list|)
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|SCR_JUMP
expr_stmt|;
operator|*
name|p
operator|++
operator|=
name|PADDR
argument_list|(
name|no_data
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|u_long
operator|)
name|p
operator|==
operator|(
name|u_long
operator|)
operator|&
name|scr
operator|->
name|data_out
operator|+
sizeof|sizeof
argument_list|(
name|scr
operator|->
name|data_out
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **	Copy and rebind a script. ** ** **========================================================== */
end_comment

begin_function
specifier|static
name|void
name|ncr_script_copy_and_bind
parameter_list|(
name|struct
name|script
modifier|*
name|script
parameter_list|,
name|ncb_p
name|np
parameter_list|)
block|{
name|ncrcmd
name|opcode
decl_stmt|,
name|new
decl_stmt|,
name|old
decl_stmt|;
name|ncrcmd
modifier|*
name|src
decl_stmt|,
modifier|*
name|dst
decl_stmt|,
modifier|*
name|start
decl_stmt|,
modifier|*
name|end
decl_stmt|;
name|int
name|relocs
decl_stmt|;
name|np
operator|->
name|script
operator|=
operator|(
expr|struct
name|script
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|script
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|np
operator|->
name|p_script
operator|=
name|vtophys
argument_list|(
name|np
operator|->
name|script
argument_list|)
expr_stmt|;
name|src
operator|=
name|script
operator|->
name|start
expr_stmt|;
name|dst
operator|=
name|np
operator|->
name|script
operator|->
name|start
expr_stmt|;
name|start
operator|=
name|src
expr_stmt|;
name|end
operator|=
name|src
operator|+
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|script
argument_list|)
operator|/
literal|4
operator|)
expr_stmt|;
while|while
condition|(
name|src
operator|<
name|end
condition|)
block|{
operator|*
name|dst
operator|++
operator|=
name|opcode
operator|=
operator|*
name|src
operator|++
expr_stmt|;
comment|/* 		**	If we forget to change the length 		**	in struct script, a field will be 		**	padded with 0. This is an illegal 		**	command. 		*/
if|if
condition|(
name|opcode
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"%s: ERROR0 IN SCRIPT at %d.\n"
argument_list|,
name|ncr_name
argument_list|(
name|np
argument_list|)
argument_list|,
name|src
operator|-
name|start
operator|-
literal|1
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
if|if
condition|(
name|DEBUG_FLAGS
operator|&
name|DEBUG_SCRIPT
condition|)
name|printf
argument_list|(
literal|"%x:<%x>\n"
argument_list|,
call|(
name|unsigned
call|)
argument_list|(
name|src
operator|-
literal|1
argument_list|)
argument_list|,
operator|(
name|unsigned
operator|)
name|opcode
argument_list|)
expr_stmt|;
comment|/* 		**	We don't have to decode ALL commands 		*/
switch|switch
condition|(
name|opcode
operator|>>
literal|28
condition|)
block|{
case|case
literal|0xc
case|:
comment|/* 			**	COPY has TWO arguments. 			*/
name|relocs
operator|=
literal|2
expr_stmt|;
if|if
condition|(
operator|(
name|src
index|[
literal|0
index|]
operator|^
name|src
index|[
literal|1
index|]
operator|)
operator|&
literal|3
condition|)
block|{
name|printf
argument_list|(
literal|"%s: ERROR1 IN SCRIPT at %d.\n"
argument_list|,
name|ncr_name
argument_list|(
name|np
argument_list|)
argument_list|,
name|src
operator|-
name|start
operator|-
literal|1
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
break|break;
case|case
literal|0x0
case|:
comment|/* 			**	MOVE (absolute address) 			*/
name|relocs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|0x8
case|:
comment|/* 			**	JUMP / CALL 			**	dont't relocate if relative :-) 			*/
if|if
condition|(
name|opcode
operator|&
literal|0x00800000
condition|)
name|relocs
operator|=
literal|0
expr_stmt|;
else|else
name|relocs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|0x4
case|:
case|case
literal|0x5
case|:
case|case
literal|0x6
case|:
case|case
literal|0x7
case|:
name|relocs
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
name|relocs
operator|=
literal|0
expr_stmt|;
break|break;
block|}
empty_stmt|;
if|if
condition|(
name|relocs
condition|)
block|{
while|while
condition|(
name|relocs
operator|--
condition|)
block|{
name|old
operator|=
operator|*
name|src
operator|++
expr_stmt|;
switch|switch
condition|(
name|old
operator|&
name|RELOC_MASK
condition|)
block|{
case|case
name|RELOC_REGISTER
case|:
name|new
operator|=
operator|(
name|old
operator|&
operator|~
name|RELOC_MASK
operator|)
operator|+
name|np
operator|->
name|paddr
expr_stmt|;
break|break;
case|case
name|RELOC_LABEL
case|:
name|new
operator|=
operator|(
name|old
operator|&
operator|~
name|RELOC_MASK
operator|)
operator|+
name|vtophys
argument_list|(
name|np
operator|->
name|script
argument_list|)
expr_stmt|;
break|break;
case|case
name|RELOC_SOFTC
case|:
name|new
operator|=
operator|(
name|old
operator|&
operator|~
name|RELOC_MASK
operator|)
operator|+
name|vtophys
argument_list|(
name|np
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0
case|:
comment|/* Don't relocate a 0 address. */
if|if
condition|(
name|old
operator|==
literal|0
condition|)
block|{
name|new
operator|=
name|old
expr_stmt|;
break|break;
block|}
comment|/* fall through */
default|default:
name|new
operator|=
name|vtophys
argument_list|(
name|old
argument_list|)
expr_stmt|;
break|break;
block|}
operator|*
name|dst
operator|++
operator|=
name|new
expr_stmt|;
block|}
block|}
else|else
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
empty_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Auto configuration. ** ** **========================================================== */
end_comment

begin_comment
comment|/*---------------------------------------------------------- ** **	Reduce the transfer length to the max value **	we can transfer safely. ** **      Reading a block greater then MAX_SIZE from the **	raw (character) device exercises a memory leak **	in the vm subsystem. This is common to ALL devices. **	We have submitted a description of this bug to **<FreeBSD-bugs@freefall.cdrom.com>. **	It should be fixed in the current release. ** **---------------------------------------------------------- */
end_comment

begin_function
name|void
name|ncr_min_phys
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
if|if
condition|(
name|bp
operator|->
name|b_bcount
operator|>
name|MAX_SIZE
condition|)
name|bp
operator|->
name|b_bcount
operator|=
name|MAX_SIZE
expr_stmt|;
block|}
end_function

begin_comment
comment|/*---------------------------------------------------------- ** **	Maximal number of outstanding requests per target. ** **---------------------------------------------------------- */
end_comment

begin_function
name|U_INT32
name|ncr_info
parameter_list|(
name|int
name|unit
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
comment|/* may be changed later */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*---------------------------------------------------------- ** **	Probe the hostadapter. ** **---------------------------------------------------------- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_function
name|int
name|ncr_probe
parameter_list|(
name|parent
parameter_list|,
name|self
parameter_list|,
name|aux
parameter_list|)
name|struct
name|device
modifier|*
name|parent
decl_stmt|,
decl|*
name|self
decl_stmt|;
end_function

begin_decl_stmt
name|void
modifier|*
name|aux
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|cfdata
modifier|*
name|cf
init|=
name|self
operator|->
name|dv_cfdata
decl_stmt|;
name|struct
name|pci_attach_args
modifier|*
name|pa
init|=
name|aux
decl_stmt|;
if|if
condition|(
operator|!
name|pci_targmatch
argument_list|(
name|cf
argument_list|,
name|pa
argument_list|)
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|pa
operator|->
name|pa_id
operator|!=
name|NCR_810_ID
operator|&&
name|pa
operator|->
name|pa_id
operator|!=
name|NCR_825_ID
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__NetBSD__ */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|ncr_probe
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|NCR_810_ID
case|:
return|return
operator|(
literal|"ncr 53c810 scsi"
operator|)
return|;
case|case
name|NCR_825_ID
case|:
return|return
operator|(
literal|"ncr 53c825 wide scsi"
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NetBSD__ */
end_comment

begin_escape
end_escape

begin_comment
comment|/*========================================================== ** ** **      Auto configuration:  attach and init a host adapter. ** ** **========================================================== */
end_comment

begin_define
define|#
directive|define
name|MIN_ASYNC_PD
value|40
end_define

begin_define
define|#
directive|define
name|MIN_SYNC_PD
value|20
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_function
name|int
name|ncr_print
parameter_list|()
block|{ }
end_function

begin_function
name|void
name|ncr_attach
parameter_list|(
name|parent
parameter_list|,
name|self
parameter_list|,
name|aux
parameter_list|)
name|struct
name|device
modifier|*
name|parent
decl_stmt|,
decl|*
name|self
decl_stmt|;
end_function

begin_decl_stmt
name|void
modifier|*
name|aux
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|pci_attach_args
modifier|*
name|pa
init|=
name|aux
decl_stmt|;
name|int
name|retval
decl_stmt|;
name|ncb_p
name|np
init|=
operator|(
name|void
operator|*
operator|)
name|self
decl_stmt|;
comment|/* 	** XXX 	** Perhaps try to figure what which model chip it is and print that 	** out. 	*/
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
comment|/* 	**	Try to map the controller chip to 	**	virtual and physical memory. 	*/
name|retval
operator|=
name|pci_map_mem
argument_list|(
name|pa
operator|->
name|pa_tag
argument_list|,
literal|0x14
argument_list|,
operator|&
name|np
operator|->
name|vaddr
argument_list|,
operator|&
name|np
operator|->
name|paddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
condition|)
return|return;
name|np
operator|->
name|sc_ih
operator|.
name|ih_fun
operator|=
name|ncr_intr
expr_stmt|;
name|np
operator|->
name|sc_ih
operator|.
name|ih_arg
operator|=
name|np
expr_stmt|;
name|np
operator|->
name|sc_ih
operator|.
name|ih_level
operator|=
name|IPL_BIO
expr_stmt|;
name|retval
operator|=
name|pci_map_int
argument_list|(
name|pa
operator|->
name|pa_tag
argument_list|,
operator|&
name|np
operator|->
name|sc_ih
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
condition|)
return|return;
else|#
directive|else
comment|/* !__NetBSD__ */
specifier|static
name|void
name|ncr_attach
parameter_list|(
name|pcici_t
name|config_id
parameter_list|,
name|int
name|unit
parameter_list|)
block|{
name|ncb_p
name|np
decl_stmt|;
if|#
directive|if
operator|!
operator|(
name|__FreeBSD__
operator|>=
literal|2
operator|)
specifier|extern
name|unsigned
name|bio_imask
decl_stmt|;
endif|#
directive|endif
comment|/* 	**	allocate structure 	*/
name|np
operator|=
operator|(
name|ncb_p
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ncb
argument_list|)
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|np
condition|)
return|return;
name|ncrp
index|[
name|unit
index|]
operator|=
name|np
expr_stmt|;
comment|/* 	**	initialize structure. 	*/
name|bzero
argument_list|(
name|np
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|np
argument_list|)
argument_list|)
expr_stmt|;
name|np
operator|->
name|unit
operator|=
name|unit
expr_stmt|;
comment|/* 	**	Try to map the controller chip to 	**	virtual and physical memory. 	*/
if|if
condition|(
operator|!
name|pci_map_mem
argument_list|(
name|config_id
argument_list|,
literal|0x14
argument_list|,
operator|&
name|np
operator|->
name|vaddr
argument_list|,
operator|&
name|np
operator|->
name|paddr
argument_list|)
condition|)
return|return;
endif|#
directive|endif
comment|/* !__NetBSD__ */
comment|/* 	**	Do chip dependent initialization. 	*/
ifdef|#
directive|ifdef
name|__NetBSD__
switch|switch
condition|(
name|pa
operator|->
name|pa_id
condition|)
block|{
else|#
directive|else
switch|switch
condition|(
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|PCI_ID_REG
argument_list|)
condition|)
block|{
endif|#
directive|endif
case|case
name|NCR_810_ID
case|:
name|np
operator|->
name|maxwide
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|NCR_825_ID
case|:
name|np
operator|->
name|maxwide
operator|=
literal|1
expr_stmt|;
break|break;
block|}
comment|/* 	**	Patch script to physical addresses 	*/
name|ncr_script_fill
argument_list|(
operator|&
name|script0
argument_list|)
expr_stmt|;
name|ncr_script_copy_and_bind
argument_list|(
operator|&
name|script0
argument_list|,
name|np
argument_list|)
expr_stmt|;
comment|/* 	**	init data structure 	*/
name|np
operator|->
name|jump_tcb
operator|.
name|l_cmd
operator|=
name|SCR_JUMP
expr_stmt|;
name|np
operator|->
name|jump_tcb
operator|.
name|l_paddr
operator|=
name|vtophys
argument_list|(
operator|&
name|np
operator|->
name|script
operator|->
name|abort
argument_list|)
expr_stmt|;
comment|/* 	**	Make the controller's registers available. 	**	Now the INB INW INL OUTB OUTW OUTL macros 	**	can be used safely. 	*/
name|np
operator|->
name|reg
operator|=
operator|(
expr|struct
name|ncr_reg
operator|*
operator|)
name|np
operator|->
name|vaddr
expr_stmt|;
comment|/* 	**  Get SCSI addr of host adapter (set by bios?). 	*/
name|np
operator|->
name|myaddr
operator|=
name|INB
argument_list|(
name|nc_scid
argument_list|)
operator|&
literal|0x07
expr_stmt|;
if|if
condition|(
operator|!
name|np
operator|->
name|myaddr
condition|)
name|np
operator|->
name|myaddr
operator|=
name|SCSI_NCR_MYADDR
expr_stmt|;
comment|/* 	**	Get the value of the chip's clock. 	**	Find the right value for scntl3. 	*/
name|ncr_getclock
argument_list|(
name|np
argument_list|)
expr_stmt|;
comment|/* 	**	Reset chip. 	*/
name|OUTB
argument_list|(
name|nc_istat
argument_list|,
name|SRST
argument_list|)
expr_stmt|;
name|OUTB
argument_list|(
name|nc_istat
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NCR_DUMP_REG
comment|/* 	**	Log the initial register contents 	*/
block|{
name|int
name|reg
decl_stmt|;
ifdef|#
directive|ifdef
name|__NetBSD__
name|u_long
name|config_id
init|=
name|pa
operator|->
name|pa_tag
decl_stmt|;
endif|#
directive|endif
for|for
control|(
name|reg
operator|=
literal|0
init|;
name|reg
operator|<
literal|256
condition|;
name|reg
operator|+=
literal|4
control|)
block|{
if|if
condition|(
name|reg
operator|%
literal|16
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"reg[%2x]"
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" %08x"
argument_list|,
operator|(
name|int
operator|)
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|reg
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|reg
operator|%
literal|16
operator|==
literal|12
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* 	**	Reset chip, once again. 	*/
name|OUTB
argument_list|(
name|nc_istat
argument_list|,
name|SRST
argument_list|)
expr_stmt|;
name|OUTB
argument_list|(
name|nc_istat
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|NCR_DUMP_REG
comment|/* 	**	Now check the cache handling of the pci chipset. 	*/
if|if
condition|(
name|ncr_snooptest
argument_list|(
name|np
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"CACHE INCORRECTLY CONFIGURED.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
empty_stmt|;
ifndef|#
directive|ifndef
name|__NetBSD__
comment|/* 	**	Install the interrupt handler. 	*/
if|if
condition|(
operator|!
name|pci_map_int
argument_list|(
name|config_id
argument_list|,
name|ncr_intr
argument_list|,
name|np
argument_list|,
operator|&
name|bio_imask
argument_list|)
condition|)
name|printf
argument_list|(
literal|"\tinterruptless mode: reduced performance.\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	**	After SCSI devices have been opened, we cannot 	**	reset the bus safely, so we do it here. 	**	Interrupt handler does the real work. 	*/
name|OUTB
argument_list|(
name|nc_scntl1
argument_list|,
name|CRST
argument_list|)
expr_stmt|;
comment|/* 	**	process the reset exception, 	**	if interrupts are not enabled yet. 	*/
name|ncr_exception
argument_list|(
name|np
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ANCIENT
name|printf
argument_list|(
literal|"%s: waiting for scsi devices to settle\n"
argument_list|,
name|ncr_name
argument_list|(
name|np
argument_list|)
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
literal|1000000
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NCR_PATCHLEVEL
name|printf
argument_list|(
literal|"%s scanning for targets 0..%d (V%d "
argument|NCR_PATCHLEVEL
literal|")\n"
argument_list|,
else|#
directive|else
argument|printf (
literal|"%s scanning for targets 0..%d (V%d)\n"
argument|,
endif|#
directive|endif
argument|ncr_name (np), MAX_TARGET-
literal|1
argument|, NCR_VERSION);
comment|/* 	**	Now let the generic SCSI driver 	**	look for the SCSI devices on the bus .. 	*/
ifndef|#
directive|ifndef
name|ANCIENT
ifdef|#
directive|ifdef
name|__NetBSD__
argument|np->sc_link.adapter_softc = np;
else|#
directive|else
comment|/* !__NetBSD__ */
argument|np->sc_link.adapter_unit = unit;
endif|#
directive|endif
comment|/* !__NetBSD__ */
argument|np->sc_link.adapter_targ = np->myaddr; 	np->sc_link.adapter      =&ncr_switch; 	np->sc_link.device       =&ncr_dev;
ifdef|#
directive|ifdef
name|__NetBSD__
argument|config_found(self,&np->sc_link, ncr_print);
else|#
directive|else
comment|/* !__NetBSD__ */
argument|scsi_attachdevs (&np->sc_link);
endif|#
directive|endif
comment|/* !__NetBSD__ */
else|#
directive|else
comment|/* ANCIENT */
argument|scsi_attachdevs (unit, np->myaddr,&ncr_switch);
endif|#
directive|endif
comment|/* ANCIENT */
comment|/* 	**	start the timeout daemon 	*/
argument|ncr_timeout (np); 	np->lasttime=
literal|0
argument|;
comment|/* 	**  Done. 	*/
argument|return; }
comment|/*========================================================== ** ** **	Process pending device interrupts. ** ** **========================================================== */
argument|int ncr_intr(np) 	ncb_p np; { 	int n =
literal|0
argument|;  	if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"["
argument|);  	if (INB(nc_istat)& (INTF|SIP|DIP)) {
comment|/* 		**	Repeat until no outstanding ints 		*/
argument|do { 			ncr_exception (np); 		} while (INB(nc_istat)& (INTF|SIP|DIP));  		n=
literal|1
argument|; 		np->ticks =
literal|100
argument|; 	};  	if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"]\n"
argument|);  	return (n); }
comment|/*========================================================== ** ** **	Start execution of a SCSI command. **	This is called from the generic SCSI driver. ** ** **========================================================== */
argument|static INT32 ncr_start (struct scsi_xfer * xp) {
ifndef|#
directive|ifndef
name|ANCIENT
ifdef|#
directive|ifdef
name|__NetBSD__
argument|ncb_p np  = xp->sc_link->adapter_softc;
else|#
directive|else
comment|/*__NetBSD__*/
argument|ncb_p np  = ncrp[xp->sc_link->adapter_unit];
endif|#
directive|endif
comment|/*__NetBSD__*/
else|#
directive|else
comment|/* ANCIENT */
argument|ncb_p np  = ncrp[xp->adapter];
endif|#
directive|endif
comment|/* ANCIENT */
argument|struct scsi_generic * cmd = xp->cmd; 	ccb_p cp; 	lcb_p lp; 	tcb_p tp =&np->target[xp->TARGET];  	int	i
argument_list|,
argument|oldspl
argument_list|,
argument|segments
argument_list|,
argument|flags = xp->flags; 	u_char	ptr
argument_list|,
argument|nego
argument_list|,
argument|idmsg; 	u_long  msglen
argument_list|,
argument|msglen2;
comment|/*--------------------------------------------- 	** 	**   Reset SCSI bus 	** 	**	Interrupt handler does the real work. 	** 	**--------------------------------------------- 	*/
argument|if (flags& SCSI_RESET) { 		OUTB (nc_scntl1, CRST); 		return(COMPLETE); 	};
comment|/*--------------------------------------------- 	** 	**      Some shortcuts ... 	** 	**--------------------------------------------- 	*/
argument|if ((xp->TARGET == np->myaddr    ) || 		(xp->TARGET>= MAX_TARGET) || 		(xp->LUN>= MAX_LUN   ) || 		(flags& SCSI_DATA_UIO)) { 		xp->error = XS_DRIVER_STUFFUP; 		return(HAD_ERROR); 	};
comment|/*--------------------------------------------- 	** 	**      Diskaccess to partial blocks? 	** 	**--------------------------------------------- 	*/
argument|if ((xp->datalen&
literal|0x1ff
argument|)&& !(tp->inqdata[
literal|0
argument|]&
literal|0x1f
argument|)) { 		switch (cmd->opcode) { 		case
literal|0x28
argument|:
comment|/* READ_BIG  (10) */
argument|case
literal|0xa8
argument|:
comment|/* READ_HUGE (12) */
argument|case
literal|0x2a
argument|:
comment|/* WRITE_BIG (10) */
argument|case
literal|0xaa
argument|:
comment|/* WRITE_HUGE(12) */
argument|PRINT_ADDR(xp); 			printf (
literal|"access to partial disk block refused.\n"
argument|); 			xp->error = XS_DRIVER_STUFFUP; 			return(HAD_ERROR); 		}; 	};
ifdef|#
directive|ifdef
name|ANCIENT
comment|/*--------------------------------------------- 	**   Ancient version of<sys/scsi/sd.c> 	**   doesn't set the DATA_IN/DATA_OUT bits. 	**   So we have to fix it .. 	**--------------------------------------------- 	*/
argument|switch (cmd->opcode) { 	case
literal|0x1a
argument|:
comment|/* MODE_SENSE    */
argument|case
literal|0x25
argument|:
comment|/* READ_CAPACITY */
argument|case
literal|0x28
argument|:
comment|/* READ_BIG (10) */
argument|xp->flags |= SCSI_DATA_IN; 		break; 	case
literal|0x2a
argument|:
comment|/* WRITE_BIG(10) */
argument|xp->flags |= SCSI_DATA_OUT; 		break; 	};
endif|#
directive|endif
comment|/* ANCIENT */
argument|if (DEBUG_FLAGS& DEBUG_TINY) { 		PRINT_ADDR(xp); 		printf (
literal|"CMD=%x F=%x L=%x "
argument|, cmd->opcode, 			(unsigned)xp->flags, (unsigned) xp->datalen); 	}
comment|/*-------------------------------------------- 	** 	**   Sanity checks ... 	**	copied from Elischer's Adaptec driver. 	** 	**-------------------------------------------- 	*/
argument|flags = xp->flags; 	if (!(flags& INUSE)) { 		printf(
literal|"%s: ?INUSE?\n"
argument|, ncr_name (np)); 		xp->flags |= INUSE; 	};  	if(flags& ITSDONE) { 		printf(
literal|"%s: ?ITSDONE?\n"
argument|, ncr_name (np)); 		xp->flags&= ~ITSDONE; 	};  	if (xp->bp) 		flags |= (SCSI_NOSLEEP);
comment|/* just to be sure */
comment|/*--------------------------------------------------- 	** 	**	Assign a ccb / bind xp 	** 	**---------------------------------------------------- 	*/
argument|if (!(cp=ncr_get_ccb (np, flags, xp->TARGET, xp->LUN))) { 		printf (
literal|"%s: no ccb.\n"
argument|, ncr_name (np)); 		xp->error = XS_DRIVER_STUFFUP; 		return(TRY_AGAIN_LATER); 	}; 	cp->xfer = xp;
comment|/*--------------------------------------------------- 	** 	**	timestamp 	** 	**---------------------------------------------------- 	*/
argument|bzero (&cp->phys.header.stamp, sizeof (struct tstamp)); 	cp->phys.header.stamp.start = time;
comment|/*---------------------------------------------------- 	** 	**	Get device quirks from a speciality table. 	** 	**	@GENSCSI@ 	**	This should be a part of the device table 	**	in "scsi_conf.c". 	** 	**---------------------------------------------------- 	*/
argument|if (tp->quirks& QUIRK_UPDATE) {
ifdef|#
directive|ifdef
name|NEW_SCSICONF
argument|tp->quirks = xp->sc_link->quirks;
else|#
directive|else
argument|tp->quirks = ncr_lookup ((char*)&tp->inqdata[
literal|0
argument|]);
endif|#
directive|endif
argument|if (tp->quirks) { 			PRINT_ADDR(xp); 			printf (
literal|"quirks=%x.\n"
argument|, tp->quirks); 		}; 	};
comment|/*--------------------------------------------------- 	** 	**	negotiation required? 	** 	**---------------------------------------------------- 	*/
argument|nego =
literal|0
argument|;  	if (tp->inqdata[
literal|7
argument|]) {
comment|/* 		**	negotiate synchronous transfers? 		*/
argument|if (!tp->period) { 			if (tp->inqdata[
literal|7
argument|]& INQ7_SYNC) { 				nego = NS_SYNC; 			} else { 				tp->period  =
literal|0xffff
argument|; 				tp->sval =
literal|0xe0
argument|; 				PRINT_ADDR(xp); 				printf (
literal|"asynchronous.\n"
argument|); 			}; 		};
comment|/* 		**	negotiate wide transfers ? 		*/
argument|if (!tp->widedone) { 			if (tp->inqdata[
literal|7
argument|]& INQ7_WIDE16) { 				if (!nego) nego = NS_WIDE; 			} else 				tp->widedone=
literal|1
argument|; 		}; 	};
comment|/*--------------------------------------------------- 	** 	**	choose a new tag ... 	** 	**---------------------------------------------------- 	*/
argument|if ((lp = tp->lp[xp->LUN])&& (lp->usetags)) {
comment|/* 		**	assign a tag to this ccb! 		*/
argument|while (!cp->tag) { 			ccb_p cp2 = lp->next_ccb; 			lp->lasttag = lp->lasttag %
literal|255
argument|+
literal|1
argument|; 			while (cp2&& cp2->tag != lp->lasttag) 				cp2 = cp2->next_ccb; 			if (cp2) continue; 			cp->tag=lp->lasttag; 			if (DEBUG_FLAGS& DEBUG_TAGS) { 				PRINT_ADDR(xp); 				printf (
literal|"using tag #%d.\n"
argument|, cp->tag); 			}; 		}; 	} else { 		cp->tag=
literal|0
argument|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ANCIENT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|!
operator|(
name|__FreeBSD__
operator|>=
literal|2
operator|)
comment|/* 		** @GENSCSI@	Bug in "/sys/scsi/cd.c" 		** 		**	/sys/scsi/cd.c initializes opennings with 2. 		**	Our info value of 1 is not respected. 		*/
argument|if (xp->sc_link&& xp->sc_link->opennings) { 			PRINT_ADDR(xp); 			printf (
literal|"opennings set to 0.\n"
argument|); 			xp->sc_link->opennings =
literal|0
argument|; 		};
endif|#
directive|endif
argument|};
comment|/*---------------------------------------------------- 	** 	**	Build the identify / tag / sdtr message 	** 	**---------------------------------------------------- 	*/
ifndef|#
directive|ifndef
name|NCR_NO_DISCONNECT
argument|idmsg = (cp==&np->ccb ? M_IDENTIFY :
literal|0xc0
argument|) | xp->LUN;
else|#
directive|else
comment|/*--------------------------------------------------------------------- 	** Some users have problems with this driver. 	** I assume that the current problems relate to a conflict between 	** a disconnect and an immediately following reconnect operation. 	** With this option you can prevent the driver from using disconnects. 	** If this removes the problems, I would know where to search further.. 	** Of course this is no solution. 	** Without disconnects the performance will be severely degraded. 	** But it may help to trace down the core problem. 	**--------------------------------------------------------------------- 	*/
argument|idmsg = M_IDENTIFY | xp->LUN;
endif|#
directive|endif
argument|cp -> scsi_smsg [
literal|0
argument|] = idmsg; 	msglen=
literal|1
argument|;  	if (cp->tag) {
comment|/* 		**	Ordered write ops, unordered read ops. 		*/
argument|switch (cmd->opcode) { 		case
literal|0x08
argument|:
comment|/* READ_SMALL (6) */
argument|case
literal|0x28
argument|:
comment|/* READ_BIG  (10) */
argument|case
literal|0xa8
argument|:
comment|/* READ_HUGE (12) */
argument|cp -> scsi_smsg [msglen] = M_SIMPLE_TAG; 			break; 		default: 			cp -> scsi_smsg [msglen] = M_ORDERED_TAG; 		}
comment|/* 		**	can be overwritten by ncrcontrol 		*/
argument|switch (np->order) { 		case M_SIMPLE_TAG: 		case M_ORDERED_TAG: 			cp -> scsi_smsg [msglen] = np->order; 		}; 		msglen++; 		cp -> scsi_smsg [msglen++] = cp -> tag; 	}  	switch (nego) { 	case NS_SYNC: 		cp -> scsi_smsg [msglen++] = M_EXTENDED; 		cp -> scsi_smsg [msglen++] =
literal|3
argument|; 		cp -> scsi_smsg [msglen++] = M_X_SYNC_REQ; 		cp -> scsi_smsg [msglen++] = tp->minsync; 		cp -> scsi_smsg [msglen++] = tp->maxoffs; 		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"sync msgout: "
argument|); 			ncr_show_msg (&cp->scsi_smsg [msglen-
literal|5
argument|]); 			printf (
literal|".\n"
argument|); 		}; 		break; 	case NS_WIDE: 		cp -> scsi_smsg [msglen++] = M_EXTENDED; 		cp -> scsi_smsg [msglen++] =
literal|2
argument|; 		cp -> scsi_smsg [msglen++] = M_X_WIDE_REQ; 		cp -> scsi_smsg [msglen++] = tp->usrwide; 		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"wide msgout: "
argument|); 			ncr_show_msg (&cp->scsi_smsg [msglen-
literal|4
argument|]); 			printf (
literal|".\n"
argument|); 		}; 		break; 	};
comment|/*---------------------------------------------------- 	** 	**	Build the identify message for getcc. 	** 	**---------------------------------------------------- 	*/
argument|cp -> scsi_smsg2 [
literal|0
argument|] = idmsg; 	msglen2 =
literal|1
argument|;
comment|/*---------------------------------------------------- 	** 	**	Build the data descriptors 	** 	**---------------------------------------------------- 	*/
argument|segments = ncr_scatter (&cp->phys, (vm_offset_t) xp->data, 					(vm_size_t) xp->datalen);  	if (segments<
literal|0
argument|) { 		xp->error = XS_DRIVER_STUFFUP; 		ncr_free_ccb(np, cp, flags); 		return(HAD_ERROR); 	};
comment|/*---------------------------------------------------- 	** 	**	Set the SAVED_POINTER. 	** 	**---------------------------------------------------- 	*/
argument|if (flags& SCSI_DATA_IN) { 		cp->phys.header.savep = vtophys (&np->script->data_in); 		cp->phys.header.goalp = cp->phys.header.savep +
literal|20
argument|+segments*
literal|16
argument|; 	} else if (flags& SCSI_DATA_OUT) { 		cp->phys.header.savep = vtophys (&np->script->data_out); 		cp->phys.header.goalp = cp->phys.header.savep +
literal|20
argument|+segments*
literal|16
argument|; 	} else { 		cp->phys.header.savep = vtophys (&np->script->no_data); 		cp->phys.header.goalp = cp->phys.header.savep; 	}; 	cp->phys.header.lastp = cp->phys.header.savep;
comment|/*---------------------------------------------------- 	** 	**	fill ccb 	** 	**---------------------------------------------------- 	** 	** 	**	physical -> virtual backlink 	**	Generic SCSI command 	*/
argument|cp->phys.header.cp		= cp;
comment|/* 	**	Startqueue 	*/
argument|cp->phys.header.launch.l_paddr	= vtophys (&np->script->select); 	cp->phys.header.launch.l_cmd	= SCR_JUMP;
comment|/* 	**	select 	*/
argument|cp->phys.select.sel_id		= xp->TARGET; 	cp->phys.select.sel_scntl3	= tp->wval; 	cp->phys.select.sel_sxfer	= tp->sval;
comment|/* 	**	message 	*/
argument|cp->phys.smsg.addr		= vtophys (&cp->scsi_smsg ); 	cp->phys.smsg.size		= msglen; 	cp->phys.smsg2.addr		= vtophys (&cp->scsi_smsg2); 	cp->phys.smsg2.size		= msglen2;
comment|/* 	**	command 	*/
ifdef|#
directive|ifdef
name|ANCIENT
argument|bcopy (cmd,&cp->cmd, sizeof (cp->cmd)); 	cp->phys.cmd.addr		= vtophys (&cp->cmd);
else|#
directive|else
comment|/* ANCIENT */
argument|cp->phys.cmd.addr		= vtophys (cmd);
endif|#
directive|endif
comment|/* ANCIENT */
argument|cp->phys.cmd.size		= xp->cmdlen;
comment|/* 	**	sense data 	*/
argument|cp->phys.sense.addr		= vtophys (&cp->xfer->sense); 	cp->phys.sense.size		= sizeof(struct scsi_sense_data);
comment|/* 	**	status 	*/
argument|cp->actualquirks		= tp->quirks; 	cp->host_status			= nego ? HS_NEGOTIATE : HS_BUSY; 	cp->scsi_status			= S_ILLEGAL; 	cp->parity_status		=
literal|0
argument|;  	cp->xerr_status			= XE_OK; 	cp->sync_status			= tp->sval; 	cp->nego_status			= nego; 	cp->wide_status			= tp->wval;
comment|/*---------------------------------------------------- 	** 	**	Critical region: starting this job. 	** 	**---------------------------------------------------- 	*/
argument|oldspl =
literal|0
argument|;
comment|/* for the sake of gcc */
argument|if (!(flags& SCSI_NOMASK)) oldspl = splbio(); 	np->lock++;
comment|/* 	**	reselect pattern and activate this job. 	*/
argument|cp->jump_ccb.l_cmd	= (SCR_JUMP ^ IFFALSE (DATA (cp->tag))); 	cp->tlimit		= time.tv_sec + xp->timeout /
literal|1000
argument|+
literal|2
argument|; 	cp->magic               = CCB_MAGIC;
comment|/* 	**	insert into startqueue. 	*/
argument|ptr = np->squeueput +
literal|1
argument|; 	if (ptr>= MAX_START) ptr=
literal|0
argument|; 	np->squeue [ptr          ] = vtophys(&np->script->idle); 	np->squeue [np->squeueput] = vtophys(&cp->phys); 	np->squeueput = ptr;  	if(DEBUG_FLAGS& DEBUG_QUEUE) 		printf (
literal|"%s: queuepos=%d tryoffset=%d.\n"
argument|, ncr_name (np), 		np->squeueput, 		(unsigned)(np->script->startpos[
literal|0
argument|]- 			(vtophys(&np->script->tryloop))));
comment|/* 	**	Script processor may be waiting for reconnect. 	**	Wake it up. 	*/
argument|OUTB (nc_istat, SIGP);
comment|/* 	**	If interrupts are enabled, return now. 	**	Command is successfully queued. 	*/
argument|np->lock--; 	if (!(flags& SCSI_NOMASK)) { 		splx (oldspl); 		if (np->lasttime) { 			if(DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"Q"
argument|); 			return(SUCCESSFULLY_QUEUED); 		}; 	};
comment|/*---------------------------------------------------- 	** 	**	Interrupts not yet enabled - have to poll. 	** 	**---------------------------------------------------- 	*/
argument|if (DEBUG_FLAGS& DEBUG_POLL) printf(
literal|"P"
argument|);  	for (i=xp->timeout; i&& !(xp->flags& ITSDONE);i--) { 		if ((DEBUG_FLAGS& DEBUG_POLL)&& (cp->host_status)) 			printf (
literal|"%c"
argument|, (cp->host_status&
literal|0xf
argument|) +
literal|'0'
argument|); 		DELAY (
literal|1000
argument|); 		ncr_exception (np); 	};
comment|/* 	**	Abort if command not done. 	*/
argument|if (!(xp->flags& ITSDONE)) { 		printf (
literal|"%s: aborting job ...\n"
argument|, ncr_name (np)); 		OUTB (nc_istat, CABRT); 		DELAY (
literal|100000
argument|); 		OUTB (nc_istat, SIGP); 		ncr_exception (np); 	};  	if (!(xp->flags& ITSDONE)) { 		printf (
literal|"%s: abortion failed at %x.\n"
argument|, 			ncr_name (np), (unsigned) INL(nc_dsp)); 		ncr_init (np,
literal|"timeout"
argument|, HS_TIMEOUT); 	};  	if (!(xp->flags& ITSDONE)) { 		cp-> host_status = HS_SEL_TIMEOUT; 		ncr_complete (np, cp); 	};  	if (DEBUG_FLAGS& DEBUG_RESULT) { 		printf (
literal|"%s: result: %x %x.\n"
argument|, 			ncr_name (np), cp->host_status, cp->scsi_status); 	}; 	if (!(flags& SCSI_NOMASK)) 		return (SUCCESSFULLY_QUEUED); 	switch (xp->error) { 	case
literal|0
argument|: return (COMPLETE); 	case XS_BUSY: return (TRY_AGAIN_LATER); 	}; 	return (HAD_ERROR); }
comment|/*========================================================== ** ** **	Complete execution of a SCSI command. **	Signal completion to the generic SCSI driver. ** ** **========================================================== */
argument|void ncr_complete (ncb_p np, ccb_p cp) { 	struct scsi_xfer * xp; 	tcb_p tp; 	lcb_p lp;
comment|/* 	**	Sanity check 	*/
argument|if (!cp || (cp->magic!=CCB_MAGIC) || !cp->xfer) return; 	cp->magic =
literal|1
argument|; 	cp->tlimit=
literal|0
argument|;
comment|/* 	**	No Reselect anymore. 	*/
argument|cp->jump_ccb.l_cmd = (SCR_JUMP);
comment|/* 	**	No starting. 	*/
argument|cp->phys.header.launch.l_paddr= vtophys (&np->script->idle);
comment|/* 	**	timestamp 	*/
argument|ncb_profile (np, cp);
argument|if (DEBUG_FLAGS& DEBUG_TINY) 		printf (
literal|"CCB=%x STAT=%x/%x\n"
argument|, (unsigned)cp&
literal|0xfff
argument|, 			cp->host_status,cp->scsi_status);  	xp  = cp->xfer; 	cp->xfer = NULL; 	tp =&np->target[xp->TARGET]; 	lp  = tp->lp[xp->LUN];
comment|/* 	**	Check for parity errors. 	*/
argument|if (cp->parity_status) { 		PRINT_ADDR(xp); 		printf (
literal|"%d parity error(s), fallback.\n"
argument|, cp->parity_status);
comment|/* 		**	fallback to asynch transfer. 		*/
argument|tp->usrsync=
literal|255
argument|; 		tp->period =
literal|0
argument|; 	};
comment|/* 	**	Check for extended errors. 	*/
argument|if (cp->xerr_status != XE_OK) { 		PRINT_ADDR(xp); 		switch (cp->xerr_status) { 		case XE_EXTRA_DATA: 			printf (
literal|"extraneous data discarded.\n"
argument|); 			break; 		case XE_BAD_PHASE: 			printf (
literal|"illegal scsi phase (4/5).\n"
argument|); 			break; 		default: 			printf (
literal|"extended error %d.\n"
argument|, cp->xerr_status); 			break; 		}; 		if (cp->host_status==HS_COMPLETE) 			cp->host_status = HS_FAIL; 	};
comment|/* 	**	Check the status. 	*/
argument|if (   (cp->host_status == HS_COMPLETE)&& (cp->scsi_status == S_GOOD)) {
comment|/* 		**	All went well. 		*/
argument|xp->resid =
literal|0
argument|;
comment|/* 		** if (cp->phys.header.lastp != cp->phys.header.goalp)... 		** 		**	@RESID@ 		**	Could dig out the correct value for resid, 		**	but it would be quite complicated. 		** 		**	The ah1542.c driver sets it to 0 too ... 		*/
comment|/* 		**	Try to assign a ccb to this nexus 		*/
argument|ncr_alloc_ccb (np, xp);
comment|/* 		**	On inquire cmd (0x12) save some data. 		*/
ifdef|#
directive|ifdef
name|ANCIENT
argument|if (cp->cmd.opcode ==
literal|0x12
argument|) {
else|#
directive|else
comment|/* ANCIENT */
argument|if (xp->cmd->opcode ==
literal|0x12
argument|) {
endif|#
directive|endif
comment|/* ANCIENT */
argument|bcopy (	xp->data,&tp->inqdata, 				sizeof (tp->inqdata));
comment|/* 			**	set number of tags 			*/
argument|ncr_setmaxtags (tp, tp->usrtags);
comment|/* 			**	prepare negotiation of synch and wide. 			*/
argument|ncr_negotiate (np, tp);
comment|/* 			**	force quirks update before next command start 			*/
argument|tp->quirks |= QUIRK_UPDATE; 		};
comment|/* 		**	Announce changes to the generic driver 		*/
argument|if (lp) { 			ncr_settags (tp, lp); 			if (lp->reqlink != lp->actlink) 				ncr_opennings (np, lp, xp); 		};  		tp->bytes     += xp->datalen; 		tp->transfers ++;  	} else if (xp->flags& SCSI_ERR_OK) {
comment|/* 		**   Not correct, but errors expected. 		*/
argument|xp->resid =
literal|0
argument|;  	} else if ((cp->host_status == HS_COMPLETE)&& (cp->scsi_status == (S_SENSE|S_GOOD))) {
comment|/* 		**   Check condition code 		*/
argument|xp->error = XS_SENSE;  		if (DEBUG_FLAGS& (DEBUG_RESULT|DEBUG_TINY)) { 			u_char * p = (u_char*)& xp->sense; 			int i; 			printf (
literal|"\n%s: sense data:"
argument|, ncr_name (np)); 			for (i=
literal|0
argument|; i<
literal|14
argument|; i++) printf (
literal|" %x"
argument|, *p++); 			printf (
literal|".\n"
argument|); 		};
argument|} else if ((cp->host_status == HS_COMPLETE)&& (cp->scsi_status == S_BUSY)) {
comment|/* 		**   Target is busy. 		*/
argument|xp->error = XS_BUSY;  	} else if ((cp->host_status == HS_SEL_TIMEOUT) 		|| (cp->host_status == HS_TIMEOUT)) {
comment|/* 		**   No response 		*/
argument|xp->error = XS_TIMEOUT;  	} else {
comment|/* 		**  Other protocol messes 		*/
argument|PRINT_ADDR(xp); 		printf (
literal|"COMMAND FAILED (%x %x) @%x.\n"
argument|, 			cp->host_status, cp->scsi_status, (unsigned)cp);  		xp->error = XS_DRIVER_STUFFUP; 	}
argument|xp->flags |= ITSDONE;
comment|/* 	**	trace output 	*/
argument|if (tp->usrflag& UF_TRACE) { 		u_char * p; 		int i; 		PRINT_ADDR(xp); 		printf (
literal|" CMD:"
argument|);
ifdef|#
directive|ifdef
name|ANCIENT
argument|p = (u_char*)&cp->cmd.opcode;
else|#
directive|else
comment|/* ANCIENT */
argument|p = (u_char*)&xp->cmd->opcode;
endif|#
directive|endif
comment|/* ANCIENT */
argument|for (i=
literal|0
argument|; i<xp->cmdlen; i++) printf (
literal|" %x"
argument|, *p++);  		if (cp->host_status==HS_COMPLETE) { 			switch (cp->scsi_status) { 			case S_GOOD: 				printf (
literal|"  GOOD"
argument|); 				break; 			case S_CHECK_COND: 				printf (
literal|"  SENSE:"
argument|); 				p = (u_char*)&xp->sense;
ifdef|#
directive|ifdef
name|ANCIENT
argument|for (i=
literal|0
argument|; i<sizeof(xp->sense); i++)
else|#
directive|else
comment|/* ANCIENT */
argument|for (i=
literal|0
argument|; i<xp->req_sense_length; i++)
endif|#
directive|endif
comment|/* ANCIENT */
argument|printf (
literal|" %x"
argument|, *p++); 				break; 			default: 				printf (
literal|"  STAT: %x\n"
argument|, cp->scsi_status); 				break; 			}; 		} else printf (
literal|"  HOSTERROR: %x"
argument|, cp->host_status); 		printf (
literal|"\n"
argument|); 	};
comment|/* 	**	Free this ccb 	*/
argument|ncr_free_ccb (np, cp, xp->flags);
comment|/* 	**	signal completion to generic driver. 	*/
ifdef|#
directive|ifdef
name|ANCIENT
argument|if (xp->when_done) 		(*(xp->when_done))(xp->done_arg,xp->done_arg2);
else|#
directive|else
comment|/* ANCIENT */
argument|scsi_done (xp);
endif|#
directive|endif
comment|/* ANCIENT */
argument|}
comment|/*========================================================== ** ** **	Signal all (or one) control block done. ** ** **========================================================== */
argument|void ncr_wakeup (ncb_p np, u_long code) {
comment|/* 	**	Starting at the default ccb and following 	**	the links, complete all jobs with a 	**	host_status greater than "disconnect". 	** 	**	If the "code" parameter is not zero, 	**	complete all jobs that are not IDLE. 	*/
argument|int s=splbio();  	ccb_p cp =&np->ccb; 	while (cp) { 		switch (cp->host_status) {  		case HS_IDLE: 			break;  		case HS_DISCONNECT: 			if(DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"D"
argument|);
comment|/* fall through */
argument|case HS_BUSY: 		case HS_NEGOTIATE: 			if (!code) break; 			cp->host_status = code;
comment|/* fall through */
argument|default: 			ncr_complete (np, cp); 			break; 		}; 		cp = cp -> link_ccb; 	}; 	splx (s); }
comment|/*========================================================== ** ** **	Start NCR chip. ** ** **========================================================== */
argument|void ncr_init (ncb_p np, char * msg, u_long code) { 	int	i; 	u_long	usrsync; 	u_char	usrwide;
comment|/* 	**	Reset chip. 	*/
argument|OUTB (nc_istat,  SRST	);
comment|/* 	**	Message. 	*/
argument|if (msg) printf (
literal|"%s: restart (%s).\n"
argument|, ncr_name (np), msg);
comment|/* 	**	Clear Start Queue 	*/
argument|for (i=
literal|0
argument|;i<MAX_START;i++) 		np -> squeue [i] = vtophys (&np->script->idle);
comment|/* 	**	Start at first entry. 	*/
argument|np->squeueput =
literal|0
argument|; 	np->script->startpos[
literal|0
argument|] = vtophys (&np->script->tryloop); 	np->script->start0  [
literal|0
argument|] = SCR_INT ^ IFFALSE (
literal|0
argument|);
comment|/* 	**	Wakeup all pending jobs. 	*/
argument|ncr_wakeup (np, code);
comment|/* 	**	Init chip. 	*/
argument|OUTB (nc_istat,
literal|0
argument|);
comment|/*  Remove Reset, abort ...          */
argument|OUTB (nc_scntl0,
literal|0xca
argument|);
comment|/*  full arb., ena parity, par->ATN  */
argument|OUTB (nc_scntl1,
literal|0x00
argument|);
comment|/*  odd parity, and remove CRST!!    */
argument|OUTB (nc_scntl3, np->rv_scntl3);
comment|/*  timing prescaler                 */
argument|OUTB (nc_scid  , RRE|np->myaddr);
comment|/*  host adapter SCSI address      */
argument|OUTW (nc_respid,
literal|1ul
argument|<<np->myaddr);
comment|/*  id to respond to               */
argument|OUTB (nc_istat , SIGP	);
comment|/*  Signal Process                   */
argument|OUTB (nc_dmode ,
literal|0xc0
argument|);
comment|/*  Burst length = 16 transfer       */
argument|OUTB (nc_dcntl , NOCOM	);
comment|/*  no single step mode, protect SFBR*/
argument|OUTB (nc_ctest4,
literal|0x08
argument|);
comment|/*  enable master parity checking    */
argument|OUTB (nc_stest2, EXT    );
comment|/*  Extended Sreq/Sack filtering     */
argument|OUTB (nc_stest3, TE     );
comment|/*  TolerANT enable                  */
argument|OUTB (nc_stime0,
literal|0xfb
argument|);
comment|/*  HTH = 1.6sec  STO = 0.1 sec.     */
comment|/* 	**	Reinitialize usrsync. 	**	Have to renegotiate synch mode. 	*/
argument|usrsync =
literal|255
argument|; 	if (SCSI_NCR_MAX_SYNC) { 		u_long period; 		period =
literal|1000000
argument|/SCSI_NCR_MAX_SYNC;
comment|/* ns = 10e6 / kHz */
argument|if (period<=
literal|11
argument|* np->ns_sync) { 			if (period<
literal|4
argument|* np->ns_sync) 				usrsync = np->ns_sync; 			else 				usrsync = period /
literal|4
argument|; 		}; 	};
comment|/* 	**	Reinitialize usrwide. 	**	Have to renegotiate wide mode. 	*/
argument|usrwide = (SCSI_NCR_MAX_WIDE); 	if (usrwide> np->maxwide) usrwide=np->maxwide;
comment|/* 	**	Fill in target structure. 	*/
argument|for (i=
literal|0
argument|;i<MAX_TARGET;i++) { 		tcb_p tp =&np->target[i];  		tp->sval    =
literal|0
argument|; 		tp->wval    = np->rv_scntl3;  		tp->usrsync = usrsync; 		tp->usrwide = usrwide;  		ncr_negotiate (np, tp); 	}
comment|/* 	**      enable ints 	*/
argument|OUTW (nc_sien , STO|HTH|MA|SGE|UDC|RST); 	OUTB (nc_dien , MDPE|BF|ABRT|SSI|SIR|IID);
comment|/* 	**    Start script processor. 	*/
argument|OUTL (nc_dsp, vtophys (&np->script->start)); }
comment|/*========================================================== ** **	Prepare the negotiation values for wide and **	synchronous transfers. ** **========================================================== */
argument|static void ncr_negotiate (struct ncb* np, struct tcb* tp) {
comment|/* 	**	minsync unit is 4ns ! 	*/
argument|u_long minsync = tp->usrsync;  	if (minsync<
literal|25
argument|) minsync=
literal|25
argument|;
comment|/* 	**	if not scsi 2 	**	don't believe FAST! 	*/
argument|if ((minsync<
literal|50
argument|)&& (tp->inqdata[
literal|2
argument|]&
literal|0x0f
argument|)<
literal|2
argument|) 		minsync=
literal|50
argument|;
comment|/* 	**	our limit .. 	*/
argument|if (minsync< np->ns_sync) 		minsync = np->ns_sync;
comment|/* 	**	divider limit 	*/
argument|if (minsync> (np->ns_sync *
literal|11
argument|) /
literal|4
argument|) 		minsync =
literal|255
argument|;  	tp->minsync = minsync; 	tp->maxoffs = (minsync<
literal|255
argument|?
literal|8
argument|:
literal|0
argument|);
comment|/* 	**	period=0: has to negotiate sync transfer 	*/
argument|tp->period=
literal|0
argument|;
comment|/* 	**	widedone=0: has to negotiate wide transfer 	*/
argument|tp->widedone=
literal|0
argument|; }
comment|/*========================================================== ** **	Switch sync mode for current job and it's target ** **========================================================== */
argument|static void ncr_setsync (ncb_p np, ccb_p cp, u_char sxfer) { 	struct scsi_xfer *xp; 	tcb_p tp; 	u_char target = INB (nc_ctest0)&
literal|7
argument|;  	assert (cp); 	if (!cp) return;  	xp = cp->xfer; 	assert (xp); 	if (!xp) return; 	assert (target == xp->TARGET&
literal|7
argument|);  	tp =&np->target[target]; 	tp->period= sxfer&
literal|0xf
argument|? ((sxfer>>
literal|5
argument|)+
literal|4
argument|) * np->ns_sync :
literal|0xffff
argument|;  	if (tp->sval == sxfer) return; 	tp->sval = sxfer;
comment|/* 	**	Bells and whistles   ;-) 	*/
argument|PRINT_ADDR(xp); 	if (sxfer&
literal|0x0f
argument|) {
comment|/* 		**  Disable extended Sreq/Sack filtering 		*/
argument|if (tp->period<=
literal|200
argument|) OUTB (nc_stest2,
literal|0
argument|); 		printf (
literal|"%s%dns (%d Mb/sec) offset %d.\n"
argument|, 			tp->period<
literal|200
argument|?
literal|"FAST SCSI-2 "
argument|:
literal|""
argument|, 			tp->period, (
literal|1000
argument|+tp->period/
literal|2
argument|)/tp->period, 			sxfer&
literal|0x0f
argument|); 	} else  printf (
literal|"asynchronous.\n"
argument|);
comment|/* 	**	set actual value and sync_status 	*/
argument|OUTB (nc_sxfer, sxfer); 	np->sync_st = sxfer;
comment|/* 	**	patch ALL ccbs of this target. 	*/
argument|for (cp =&np->ccb; cp; cp = cp->link_ccb) { 		if (!cp->xfer) continue; 		if (cp->xfer->TARGET != target) continue; 		cp->sync_status = sxfer; 	}; }
comment|/*========================================================== ** **	Switch wide mode for current job and it's target ** **========================================================== */
argument|static void ncr_setwide (ncb_p np, ccb_p cp, u_char wide) { 	struct scsi_xfer *xp; 	u_short target = INB (nc_ctest0)&
literal|7
argument|; 	tcb_p tp; 	u_char	scntl3 = np->rv_scntl3 | (wide ? EWS :
literal|0
argument|);  	assert (cp); 	if (!cp) return;  	xp = cp->xfer; 	assert (xp); 	if (!xp) return; 	assert (target == xp->TARGET&
literal|7
argument|);  	tp =&np->target[target]; 	tp->widedone  =  wide+
literal|1
argument|; 	if (tp->wval == scntl3) return; 	tp->wval = scntl3;
comment|/* 	**	Bells and whistles   ;-) 	*/
argument|PRINT_ADDR(xp); 	if (scntl3& EWS) 		printf (
literal|"WIDE SCSI (16 bit) enabled.\n"
argument|); 	else 		printf (
literal|"WIDE SCSI disabled.\n"
argument|);
comment|/* 	**	set actual value and sync_status 	*/
argument|OUTB (nc_scntl3, scntl3); 	np->wide_st = scntl3;
comment|/* 	**	patch ALL ccbs of this target. 	*/
argument|for (cp =&np->ccb; cp; cp = cp->link_ccb) { 		if (!cp->xfer) continue; 		if (cp->xfer->TARGET != target) continue; 		cp->wide_status = scntl3; 	}; }
comment|/*========================================================== ** **	Switch tagged mode for a target. ** **========================================================== */
argument|static void ncr_setmaxtags (tcb_p tp, u_long usrtags) { 	int l; 	tp->usrtags = usrtags; 	for (l=
literal|0
argument|; l<MAX_LUN; l++) { 		lcb_p lp; 		if (!tp) break; 		lp=tp->lp[l]; 		if (!lp) continue; 		ncr_settags (tp, lp); 	}; }  static void ncr_settags (tcb_p tp, lcb_p lp) { 	u_char reqtags
argument_list|,
argument|tmp; 	 	if ((!tp) || (!lp)) return;
comment|/* 	**	only devices capable of tagges commands 	**	only disk devices 	**	only if enabled by user .. 	*/
argument|if ((  tp->inqdata[
literal|7
argument|]& INQ7_QUEUE)&& ((tp->inqdata[
literal|0
argument|]&
literal|0x1f
argument|)==
literal|0x00
argument|)&& tp->usrtags) { 		reqtags = tp->usrtags; 		if (lp->actlink<=
literal|1
argument|) 			lp->usetags=reqtags; 	} else { 		reqtags =
literal|1
argument|; 		if (lp->actlink<=
literal|1
argument|) 			lp->usetags=
literal|0
argument|; 	};
comment|/* 	**	don't announce more than available. 	*/
argument|tmp = lp->actccbs; 	if (tmp> reqtags) tmp = reqtags; 	lp->reqlink = tmp;
comment|/* 	**	don't discard if announced. 	*/
argument|tmp = lp->actlink; 	if (tmp< reqtags) tmp = reqtags; 	lp->reqccbs = tmp; }
comment|/*---------------------------------------------------- ** **	handle user commands ** **---------------------------------------------------- */
argument|static void ncr_usercmd (ncb_p np) { 	u_char t; 	tcb_p tp;  	switch (np->user.cmd) {  	case
literal|0
argument|: return;  	case UC_SETSYNC: 		for (t=
literal|0
argument|; t<MAX_TARGET; t++) { 			if (!((np->user.target>>t)&
literal|1
argument|)) continue; 			tp =&np->target[t]; 			tp->usrsync = np->user.data; 			ncr_negotiate (np, tp); 		}; 		break;  	case UC_SETTAGS: 		if (np->user.data> MAX_TAGS) 			break; 		for (t=
literal|0
argument|; t<MAX_TARGET; t++) { 			if (!((np->user.target>>t)&
literal|1
argument|)) continue; 			ncr_setmaxtags (&np->target[t], np->user.data); 		}; 		break;  	case UC_SETDEBUG: 		ncr_debug = np->user.data; 		break;  	case UC_SETORDER: 		np->order = np->user.data; 		break;  	case UC_SETWIDE: 		for (t=
literal|0
argument|; t<MAX_TARGET; t++) { 			u_long size; 			if (!((np->user.target>>t)&
literal|1
argument|)) continue; 			tp =&np->target[t]; 			size = np->user.data; 			if (size> np->maxwide) size=np->maxwide; 			tp->usrwide = size; 			ncr_negotiate (np, tp); 		}; 		break;
argument|case UC_SETFLAG: 		for (t=
literal|0
argument|; t<MAX_TARGET; t++) { 			if (!((np->user.target>>t)&
literal|1
argument|)) continue; 			tp =&np->target[t]; 			tp->usrflag = np->user.data; 		}; 		break; 	} 	np->user.cmd=
literal|0
argument|; }
comment|/*========================================================== ** ** **	ncr timeout handler. ** ** **========================================================== ** **	Misused to keep the driver running when **	interrupts are not configured correctly. ** **---------------------------------------------------------- */
argument|static void ncr_timeout (ncb_p np) { 	u_long	thistime = time.tv_sec; 	u_long	step  = np->ticks; 	u_long	count =
literal|0
argument|; 	long signed   t; 	ccb_p cp;  	if (np->lasttime != thistime) {
comment|/* 		**	block ncr interupts 		*/
argument|int oldspl = splbio(); 		np->lasttime = thistime;  		ncr_usercmd (np);
comment|/*---------------------------------------------------- 		** 		**	handle ncr chip timeouts 		** 		**	Assumption: 		**	We have a chance to arbitrate for the 		**	SCSI bus at least every 10 seconds. 		** 		**---------------------------------------------------- 		*/
argument|t = thistime - np->heartbeat;  		if (t<
literal|2
argument|) np->latetime=
literal|0
argument|; else np->latetime++;  		if (np->latetime>
literal|2
argument|) {
comment|/* 			**      If there are no requests, the script 			**      processor will sleep on SEL_WAIT_RESEL. 			**      But we have to check whether it died. 			**      Let's wake it up. 			*/
argument|OUTB (nc_istat, SIGP); 		};  		if (np->latetime>
literal|10
argument|) {
comment|/* 			**	Although we tried to wakeup it, 			**	the script processor didn't answer. 			** 			**	May be a target is hanging, 			**	or another initator lets a tape device 			**	rewind with disconnect disabled :-( 			** 			**	We won't accept that. 			*/
argument|printf (
literal|"%s: reset by timeout.\n"
argument|, ncr_name (np)); 			OUTB (nc_istat, SRST); 			OUTB (nc_istat,
literal|0
argument|); 			if (INB (nc_sbcl)& CBSY) 				OUTB (nc_scntl1, CRST); 			ncr_init (np, NULL, HS_TIMEOUT); 			np->heartbeat = thistime; 		};
comment|/*---------------------------------------------------- 		** 		**	handle ccb timeouts 		** 		**---------------------------------------------------- 		*/
argument|for (cp=&np->ccb; cp; cp=cp->link_ccb) {
comment|/* 			**	look for timed out ccbs. 			*/
argument|if (!cp->host_status) continue; 			count++; 			if (cp->tlimit> thistime) continue;
comment|/* 			**	Disable reselect. 			**      Remove it from startqueue. 			*/
argument|cp->jump_ccb.l_cmd = (SCR_JUMP); 			if (cp->phys.header.launch.l_paddr == 				vtophys (&np->script->select)) { 				printf (
literal|"%s: timeout ccb=%x (skip)\n"
argument|, 					ncr_name (np), (unsigned)cp); 				cp->phys.header.launch.l_paddr 				= vtophys (&np->script->skip); 			};  			switch (cp->host_status) {  			case HS_BUSY: 			case HS_NEGOTIATE:
comment|/* 				** still in start queue ? 				*/
argument|if (cp->phys.header.launch.l_paddr == 					vtophys (&np->script->skip)) 					continue;
comment|/* fall through */
argument|case HS_DISCONNECT: 				cp->host_status=HS_TIMEOUT; 			}; 			cp->tag =
literal|0
argument|;
comment|/* 			**	wakeup this ccb. 			*/
argument|ncr_complete (np, cp); 		}; 		splx (oldspl); 	}
argument|timeout (TIMEOUT ncr_timeout, (caddr_t) np, step ? step :
literal|1
argument|);  	if ((INB(nc_istat)& (INTF|SIP|DIP))&& !np->lock) {
comment|/* 		**	Process pending interrupts. 		*/
argument|int	oldspl	= splbio (); 		if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"{"
argument|); 		ncr_exception (np); 		if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"}"
argument|); 		splx (oldspl); 	}; }
comment|/*========================================================== ** ** **	ncr chip exception handler. ** ** **========================================================== */
argument|void ncr_exception (ncb_p np) { 	u_char  istat
argument_list|,
argument|dstat; 	u_short sist; 	u_long	dsp; 	int	i;
comment|/* 	**	interrupt on the fly ? 	*/
argument|while ((istat = INB (nc_istat))& INTF) { 		if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"F"
argument|); 		OUTB (nc_istat, INTF); 		np->profile.num_fly++; 		ncr_wakeup (np,
literal|0
argument|); 	};  	if (!(istat& (SIP|DIP))) return;
comment|/* 	**	Steinbach's Guideline for Systems Programming: 	**	Never test for an error condition you don't know how to handle. 	*/
argument|dstat = INB (nc_dstat); 	sist  = INW (nc_sist) ; 	np->profile.num_int++;  	if (DEBUG_FLAGS& DEBUG_TINY) 		printf (
literal|"<%d|%x:%x|%x:%x>"
argument|, 			INB(nc_scr0), 			dstat,sist, 			(unsigned)INL(nc_dsp), 			(unsigned)INL(nc_dbc)); 	if ((dstat==DFE)&& (sist==PAR)) return;
comment|/*========================================================== ** **	First the normal cases. ** **========================================================== */
comment|/*------------------------------------------- 	**	SCSI reset 	**------------------------------------------- 	*/
argument|if (sist& RST) { 		ncr_init (np,
literal|"scsi reset"
argument|, HS_RESET); 		return; 	};
comment|/*------------------------------------------- 	**	selection timeout 	** 	**	IID excluded from dstat mask! 	**	(chip bug) 	**------------------------------------------- 	*/
argument|if ((sist& STO)&& 		!(sist& (GEN|HTH|MA|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR))) { 		ncr_int_sto (np); 		return; 	};
comment|/*------------------------------------------- 	**      Phase mismatch. 	**------------------------------------------- 	*/
argument|if ((sist& MA)&& 		!(sist& (STO|GEN|HTH|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR|IID))) { 		ncr_int_ma (np); 		return; 	};
comment|/*---------------------------------------- 	**	move command with length 0 	**---------------------------------------- 	*/
argument|if ((dstat& IID)&& 		!(sist& (STO|GEN|HTH|MA|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR))&& 		((INL(nc_dbc)&
literal|0xf8000000
argument|) == SCR_MOVE_TBL)) {
comment|/* 		**      Target wants more data than available. 		**	The "no_data" script will do it. 		*/
argument|OUTL (nc_dsp, vtophys(&np->script->no_data)); 		return; 	};
comment|/*------------------------------------------- 	**	Programmed interrupt 	**------------------------------------------- 	*/
argument|if ((dstat& SIR)&& 		!(sist& (STO|GEN|HTH|MA|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|IID))&& 		(INB(nc_dsps)<= SIR_MAX)) { 		ncr_int_sir (np); 		return; 	};
comment|/*======================================== 	**	do the register dump 	**======================================== 	*/
argument|if (time.tv_sec - np->regtime.tv_sec>
literal|10
argument|) { 		int i; 		np->regtime = time; 		for (i=
literal|0
argument|; i<sizeof(np->regdump); i++) 			((char*)&np->regdump)[i] = ((char*)np->reg)[i]; 		np->regdump.nc_dstat = dstat; 		np->regdump.nc_sist  = sist; 	};
comment|/*========================================= 	**	log message for real hard errors 	**=========================================  	"ncr0 targ 0?: ERROR (ds:si) (so-si-sd) (sxfer/scntl3) @ (dsp:dbc)." 	"              reg: r0 r1 r2 r3 r4 r5 r6 ..... rf."  	exception register: 		ds:	dstat 		si:	sist  	SCSI bus lines: 		so:	control lines as driver by NCR. 		si:	control lines as seen by NCR. 		sd:	scsi data lines as seen by NCR.  	wide/fastmode: 		sxfer:	(see the manual) 		scntl3:	(see the manual)  	current script command: 		dsp:	script adress (relative to start of script). 		dbc:	first word of script command.  	First 16 register of the chip: 		r0..rf  	============================================= 	*/
argument|printf (
literal|"%s targ %d?: ERROR (%x:%x) (%x-%x-%x) (%x/%x) @ (%x:%x).\n"
argument|, 		ncr_name (np), INB (nc_ctest0)&
literal|7
argument|, dstat, sist, 		INB (nc_socl), INB (nc_sbcl), INB (nc_sbdl), 		INB (nc_sxfer),INB (nc_scntl3), 		((unsigned) (dsp = INL (nc_dsp))) - (unsigned) np->p_script, 		(unsigned) INL (nc_dbc)); 	printf (
literal|"              reg:"
argument|); 	for (i=
literal|0
argument|; i<
literal|16
argument|;i++) 		printf (
literal|" %x"
argument|, ((u_char*)np->reg)[i]); 	printf (
literal|".\n"
argument|);
comment|/*---------------------------------------- 	**	clean up the dma fifo 	**---------------------------------------- 	*/
argument|if ( (INB(nc_sstat0)& (ILF|ORF|OLF)   ) || 	     (INB(nc_sstat1)& (FF3210)        ) || 	     (INB(nc_sstat2)& (ILF1|ORF1|OLF1)) ||
comment|/* wide .. */
argument|!(dstat& DFE)) { 		printf (
literal|"%s: have to clear fifos.\n"
argument|, ncr_name (np)); 		OUTB (nc_stest3, TE|CSF);
comment|/* clear scsi fifo */
argument|OUTB (nc_ctest3, CLF);
comment|/* clear dma fifo  */
argument|}
comment|/*---------------------------------------- 	**	unexpected disconnect 	**---------------------------------------- 	*/
argument|if ((sist& UDC)&& 		!(sist& (STO|GEN|HTH|MA|SGE|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR|IID))) { 		OUTB (nc_scr0, HS_UNEXPECTED); 		OUTL (nc_dsp, vtophys(&np->script->cleanup)); 		return; 	};
comment|/*---------------------------------------- 	**	cannot disconnect 	**---------------------------------------- 	*/
argument|if ((dstat& IID)&& 		!(sist& (STO|GEN|HTH|MA|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR))&& 		((INL(nc_dbc)&
literal|0xf8000000
argument|) == SCR_WAIT_DISC)) {
comment|/* 		**      Unexpected data cycle while waiting for disconnect. 		*/
argument|if (INB(nc_sstat2)& LDSC) {
comment|/* 			**	It's an early reconnect. 			**	Let's continue ... 			*/
argument|OUTB (nc_dcntl, (STD|NOCOM));
comment|/* 			**	info message 			*/
argument|printf (
literal|"%s: XXX INFO: LDSC while IID.\n"
argument|, 				ncr_name (np)); 			return; 		}; 		printf (
literal|"%s: target %d? doesn't release the bus.\n"
argument|, 			ncr_name (np), INB (nc_ctest0)&
literal|7
argument|);
comment|/* 		**	return without restarting the NCR. 		**	timeout will do the real work. 		*/
argument|return; 	};
comment|/*---------------------------------------- 	**	single step 	**---------------------------------------- 	*/
argument|if ((dstat& SSI)&& 		!(sist& (STO|GEN|HTH|MA|SGE|UDC|RST|PAR))&& 		!(dstat& (MDPE|BF|ABRT|SIR|IID))) { 		OUTB (nc_dcntl, (STD|NOCOM)); 		return; 	};
comment|/* **	@RECOVER@ HTH, SGE, ABRT. ** **	We should try to recover from these interrupts. **	They may occur if there are problems with synch transfers, **	or if targets are powerswitched while the driver is running. */
argument|if (sist& SGE) { 		OUTB (nc_ctest3, CLF);
comment|/* clear scsi offsets */
argument|}
comment|/* 	**	Freeze controller to be able to read the messages. 	*/
argument|if (DEBUG_FLAGS& DEBUG_FREEZE) { 		int i; 		unsigned char val; 		for (i=
literal|0
argument|; i<
literal|0x60
argument|; i++) { 			switch (i%
literal|16
argument|) {  			case
literal|0
argument|: 				printf (
literal|"%s: reg[%d0]: "
argument|, 					ncr_name(np),i/
literal|16
argument|); 				break; 			case
literal|4
argument|: 			case
literal|8
argument|: 			case
literal|12
argument|: 				printf (
literal|" "
argument|); 				break; 			}; 			val = ((unsigned char*) np->vaddr) [i]; 			printf (
literal|" %x%x"
argument|, val/
literal|16
argument|, val%
literal|16
argument|); 			if (i%
literal|16
argument|==
literal|15
argument|) printf (
literal|".\n"
argument|); 		};  		untimeout (TIMEOUT ncr_timeout, (caddr_t) np);  		printf (
literal|"%s: halted!\n"
argument|, ncr_name(np));
comment|/* 		**	don't restart controller ... 		*/
argument|OUTB (nc_istat,  SRST); 		return; 	};
comment|/* 	**	sorry, have to kill ALL jobs ... 	*/
argument|ncr_init (np,
literal|"fatal error"
argument|, HS_FAIL); }
comment|/*========================================================== ** **	ncr chip exception handler for selection timeout ** **========================================================== ** **	There seems to be a bug in the 53c810. **	Although a STO-interrupt is pending, **	it continues executing script commands. **	But it will fail and interrupt (IID) on **	the next instruction where it's looking **	for a valid phase. ** **---------------------------------------------------------- */
argument|void ncr_int_sto (ncb_p np) { 	u_long dsa
argument_list|,
argument|scratcha
argument_list|,
argument|diff; 	ccb_p cp; 	if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"T"
argument|);
comment|/* 	**	look for ccb and set the status. 	*/
argument|dsa = INL (nc_dsa); 	cp =&np->ccb; 	while (cp&& (vtophys(&cp->phys) != dsa)) 		cp = cp->link_ccb;  	if (cp) { 		cp-> host_status = HS_SEL_TIMEOUT; 		ncr_complete (np, cp); 	};
comment|/* 	**	repair start queue 	*/
argument|scratcha = INL (nc_scratcha); 	diff = scratcha - vtophys(&np->script->tryloop);  	assert ((diff<= MAX_START *
literal|20
argument|)&& !(diff %
literal|20
argument|));  	if ((diff<= MAX_START *
literal|20
argument|)&& !(diff %
literal|20
argument|)) { 		np->script->startpos[
literal|0
argument|] = scratcha; 		OUTL (nc_dsp, vtophys (&np->script->start)); 		return; 	}; 	ncr_init (np,
literal|"selection timeout"
argument|, HS_FAIL); }
comment|/*========================================================== ** ** **	ncr chip exception handler for phase errors. ** ** **========================================================== ** **	We have to construct a new transfer descriptor, **	to transfer the rest of the current block. ** **---------------------------------------------------------- */
argument|static void ncr_int_ma (ncb_p np) { 	u_long	dbc; 	u_long	rest; 	u_long	dsa; 	u_long	dsp; 	u_long	nxtdsp; 	u_long	*vdsp; 	u_long	oadr
argument_list|,
argument|olen; 	u_long	*tblp
argument_list|,
argument|*newcmd; 	u_char	cmd
argument_list|,
argument|sbcl
argument_list|,
argument|delta
argument_list|,
argument|ss0
argument_list|,
argument|ss2; 	ccb_p	cp;  	dsp = INL (nc_dsp); 	dsa = INL (nc_dsa); 	dbc = INL (nc_dbc); 	ss0 = INB (nc_sstat0); 	ss2 = INB (nc_sstat2); 	sbcl= INB (nc_sbcl);  	cmd = dbc>>
literal|24
argument|; 	rest= dbc&
literal|0xffffff
argument|; 	delta=(INB (nc_dfifo) - rest)&
literal|0x7f
argument|;
comment|/* 	**	The data in the dma fifo has not been transfered to 	**	the target -> add the amount to the rest 	**	and clear the data. 	**	Check the sstat2 register in case of wide transfer. 	*/
argument|if (! (INB(nc_dstat)& DFE)) rest += delta; 	if (ss0& OLF) rest++; 	if (ss0& ORF) rest++; 	if (INB(nc_scntl3)& EWS) { 		if (ss2& OLF1) rest++; 		if (ss2& ORF1) rest++; 	}; 	OUTB (nc_ctest3, CLF   );
comment|/* clear dma fifo  */
argument|OUTB (nc_stest3, TE|CSF);
comment|/* clear scsi fifo */
comment|/* 	**	verify cp 	*/
argument|dsa = INL (nc_dsa); 	cp =&np->ccb; 	while (cp&& (vtophys(&cp->phys) != dsa)) 		cp = cp->link_ccb;  	assert (cp == np->header.cp); 	assert (cp); 	if (!cp) 		return;
comment|/* 	**	find the interrupted script command, 	**	and the address at where to continue. 	*/
argument|if (dsp == vtophys (&cp->patch[
literal|2
argument|])) { 		vdsp =&cp->patch[
literal|0
argument|]; 		nxtdsp = vdsp[
literal|3
argument|]; 	} else if (dsp == vtophys (&cp->patch[
literal|6
argument|])) { 		vdsp =&cp->patch[
literal|4
argument|]; 		nxtdsp = vdsp[
literal|3
argument|]; 	} else { 		vdsp = (u_long*) ((char*)np->script - vtophys(np->script) + dsp -
literal|8
argument|); 		nxtdsp = dsp; 	};
comment|/* 	**	log the information 	*/
argument|if (DEBUG_FLAGS& (DEBUG_TINY|DEBUG_PHASE)) { 		printf (
literal|"P%d%d "
argument|,cmd&
literal|7
argument|, sbcl&
literal|7
argument|); 		printf (
literal|"RL=%d D=%d SS0=%x "
argument|, 			(unsigned) rest, (unsigned) delta, ss0); 	}; 	if (DEBUG_FLAGS& DEBUG_PHASE) { 		printf (
literal|"\nCP=%x CP2=%x DSP=%x NXT=%x VDSP=%x CMD=%x "
argument|, 			(unsigned)cp, (unsigned)np->header.cp, 			(unsigned)dsp, 			(unsigned)nxtdsp, (unsigned)vdsp, cmd); 	};
comment|/* 	**	get old startaddress and old length. 	*/
argument|oadr = vdsp[
literal|1
argument|];  	if (cmd&
literal|0x10
argument|) {
comment|/* Table indirect */
argument|tblp = (u_long*) ((char*)&cp->phys + oadr); 		olen = tblp[
literal|0
argument|]; 		oadr = tblp[
literal|1
argument|]; 	} else { 		tblp = (u_long*)
literal|0
argument|; 		olen = vdsp[
literal|0
argument|]&
literal|0xffffff
argument|; 	};
argument|if (DEBUG_FLAGS& DEBUG_PHASE) { 		printf (
literal|"OCMD=%x\nTBLP=%x OLEN=%x OADR=%x\n"
argument|, 			(unsigned) (vdsp[
literal|0
argument|]>>
literal|24
argument|), 			(unsigned) tblp, 			(unsigned) olen, 			(unsigned) oadr); 	};
comment|/* 	**	if old phase not dataphase, leave here. 	*/
argument|assert (cmd == (vdsp[
literal|0
argument|]>>
literal|24
argument|)); 	if (cmd&
literal|0x06
argument|) { 		PRINT_ADDR(cp->xfer); 		printf (
literal|"phase change %d-%d %d@%x resid=%d.\n"
argument|, 			cmd&
literal|7
argument|, sbcl&
literal|7
argument|, (unsigned)olen, 			(unsigned)oadr, (unsigned)rest);  		OUTB (nc_dcntl, (STD|NOCOM)); 		return; 	};
comment|/* 	**	choose the correct patch area. 	**	if savep points to one, choose the other. 	*/
argument|newcmd = cp->patch; 	if (cp->phys.header.savep == vtophys (newcmd)) newcmd+=
literal|4
argument|;
comment|/* 	**	fillin the commands 	*/
argument|newcmd[
literal|0
argument|] = ((cmd&
literal|0x0f
argument|)<<
literal|24
argument|) | rest; 	newcmd[
literal|1
argument|] = oadr + olen - rest; 	newcmd[
literal|2
argument|] = SCR_JUMP; 	newcmd[
literal|3
argument|] = nxtdsp;  	if (DEBUG_FLAGS& DEBUG_PHASE) { 		PRINT_ADDR(cp->xfer); 		printf (
literal|"newcmd[%d] %x %x %x %x.\n"
argument|, 			newcmd - cp->patch, 			(unsigned)newcmd[
literal|0
argument|], 			(unsigned)newcmd[
literal|1
argument|], 			(unsigned)newcmd[
literal|2
argument|], 			(unsigned)newcmd[
literal|3
argument|]); 	}
comment|/* 	**	fake the return address (to the patch). 	**	and restart script processor at dispatcher. 	*/
argument|np->profile.num_break++; 	OUTL (nc_temp, vtophys (newcmd)); 	OUTL (nc_dsp, vtophys (&np->script->dispatch)); }
comment|/*========================================================== ** ** **      ncr chip exception handler for programmed interrupts. ** ** **========================================================== */
argument|static int ncr_show_msg (u_char * msg) { 	u_char i; 	printf (
literal|"%x"
argument|,*msg); 	if (*msg==M_EXTENDED) { 		for (i=
literal|1
argument|;i<
literal|8
argument|;i++) { 			if (i-
literal|1
argument|>msg[
literal|1
argument|]) break; 			printf (
literal|"-%x"
argument|,msg[i]); 		}; 		return (i+
literal|1
argument|); 	} else if ((*msg&
literal|0xf0
argument|) ==
literal|0x20
argument|) { 		printf (
literal|"-%x"
argument|,msg[
literal|1
argument|]); 		return (
literal|2
argument|); 	}; 	return (
literal|1
argument|); }  void ncr_int_sir (ncb_p np) { 	u_char chg
argument_list|,
argument|ofs
argument_list|,
argument|per
argument_list|,
argument|fak
argument_list|,
argument|wide; 	u_char num = INB (nc_dsps); 	ccb_p	cp=
literal|0
argument|; 	u_long	dsa; 	u_char	target = INB (nc_ctest0)&
literal|7
argument|; 	tcb_p	tp     =&np->target[target]; 	int     i; 	if (DEBUG_FLAGS& DEBUG_TINY) printf (
literal|"I#%d"
argument|, num);  	switch (num) { 	case SIR_SENSE_RESTART: 	case SIR_STALL_RESTART: 		break;  	default:
comment|/* 		**	lookup the ccb 		*/
argument|dsa = INL (nc_dsa); 		cp =&np->ccb; 		while (cp&& (vtophys(&cp->phys) != dsa)) 			cp = cp->link_ccb;  		assert (cp == np->header.cp); 		assert (cp); 		if (!cp) 			goto out; 	}  	switch (num) {
comment|/*-------------------------------------------------------------------- ** **	Processing of interrupted getcc selects ** **-------------------------------------------------------------------- */
argument|case SIR_SENSE_RESTART:
comment|/*------------------------------------------ 		**	Script processor is idle. 		**	Look for interrupted "check cond" 		**------------------------------------------ 		*/
argument|if (DEBUG_FLAGS& DEBUG_RESTART) 			printf (
literal|"%s: int#%d"
argument|,ncr_name (np),num); 		cp = (ccb_p)
literal|0
argument|; 		for (i=
literal|0
argument|; i<MAX_TARGET; i++) { 			if (DEBUG_FLAGS& DEBUG_RESTART) printf (
literal|" t%d"
argument|, i); 			tp =&np->target[i]; 			if (DEBUG_FLAGS& DEBUG_RESTART) printf (
literal|"+"
argument|); 			cp = tp->hold_cp; 			if (!cp) continue; 			if (DEBUG_FLAGS& DEBUG_RESTART) printf (
literal|"+"
argument|); 			if ((cp->host_status==HS_BUSY)&& 				(cp->scsi_status==S_CHECK_COND)) 				break; 			if (DEBUG_FLAGS& DEBUG_RESTART) printf (
literal|"- (remove)"
argument|); 			tp->hold_cp = cp = (ccb_p)
literal|0
argument|; 		};  		if (cp) { 			if (DEBUG_FLAGS& DEBUG_RESTART) 				printf (
literal|"+ restart job ..\n"
argument|); 			OUTL (nc_dsa, vtophys (&cp->phys)); 			OUTL (nc_dsp, vtophys (&np->script->getcc)); 			return; 		};
comment|/* 		**	no job, resume normal processing 		*/
argument|if (DEBUG_FLAGS& DEBUG_RESTART) printf (
literal|" -- remove trap\n"
argument|); 		np->script->start0[
literal|0
argument|] =  SCR_INT ^ IFFALSE (
literal|0
argument|); 		break;  	case SIR_SENSE_FAILED:
comment|/*------------------------------------------- 		**	While trying to reselect for 		**	getting the condition code, 		**	a target reselected us. 		**------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		if (DEBUG_FLAGS& DEBUG_RESTART) 			printf (
literal|"in getcc reselect by t%d.\n"
argument|, 				INB(nc_ssid)&
literal|7
argument|);
comment|/* 		**	Mark this job 		*/
argument|cp->host_status = HS_BUSY; 		cp->scsi_status = S_CHECK_COND; 		np->target[cp->xfer->TARGET].hold_cp = cp;
comment|/* 		**	And patch code to restart it. 		*/
argument|np->script->start0[
literal|0
argument|] =  SCR_INT; 		break;
comment|/*----------------------------------------------------------------------------- ** **	Was Sie schon immer ueber transfermode negotiation wissen wollten ... ** **	We try to negotiate sync and wide transfer only after **	a successfull inquire command. We look to byte 7 of the **	inquire data to determine the capabilities if the target. ** **	When we try to negotiate, we append the negotiation message **	to the identify and (maybe) simpletag message. **	The host status field is set to HS_NEGOTIATE to mark this **	situation. ** **	If the target doesn't answer this message immidiately **	(as required by the standard), the SIR_NEGO_FAIL interrupt **	will be raised eventually. **	The handler removes the HS_NEGOTIATE status, and sets the **	negotiated value to the default (async / nowide). ** **	If we receive a matching answer immediately, we check it **	for validity, and set the values. ** **	If we receive a Reject message immediately, we assume the **	negotiation has failed, and set to the standard values. ** **	If we receive a negotiation message while not in HS_NEGOTIATE **	state, it's a target initiated negotiation. We prepare a **	(hopefully) valid answer, set the values, and send this **	answer back to the target. ** **	If the target doesn't fetch the answer (no message out phase), **	we assume the negotiation has failed, and set the values to **	the default. ** **	When we set the values, we set in all ccbs belonging to this **	target, in the controllers register, and in the "phys" **	field of the controllers struct ncb. ** **	Possible cases:            hs  sir   msg_in value  send   goto **	We try try to negotiate: **	-> target doesnt't msgin   NEG FAIL  noop   defa.  -      dispatch **	-> target rejected our msg NEG FAIL  reject defa.  -      dispatch **	-> target answered  (ok)   NEG SYNC  sdtr   set    -      clrack **	-> target answered (!ok)   NEG SYNC  sdtr   defa.  REJ--->msg_bad **	-> target answered  (ok)   NEG WIDE  wdtr   set    -      clrack **	-> target answered (!ok)   NEG WIDE  wdtr   defa.  REJ--->msg_bad **	-> any other msgin         NEG FAIL  noop   defa   -      dispatch ** **	Target tries to negotiate: **	-> incoming message        --- SYNC  sdtr   set    SDTR   - **	-> incoming message        --- WIDE  wdtr   set    WDTR   - **      We sent our answer: **	-> target doesn't msgout   --- PROTO ?      defa.  -      dispatch ** **----------------------------------------------------------------------------- */
argument|case SIR_NEGO_FAILED:
comment|/*------------------------------------------------------- 		** 		**	Negotiation failed. 		**	Target doesn't send an answer message, 		**	or target rejected our message. 		** 		**      Remove negotiation request. 		** 		**------------------------------------------------------- 		*/
argument|OUTB (HS_PRT, HS_BUSY);
comment|/* fall through */
argument|case SIR_NEGO_PROTO:
comment|/*------------------------------------------------------- 		** 		**	Negotiation failed. 		**	Target doesn't fetch the answer message. 		** 		**------------------------------------------------------- 		*/
argument|if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"negotiation failed sir=%x status=%x.\n"
argument|, 				num, cp->nego_status); 		};
comment|/* 		**	any error in negotiation: 		**	fall back to default mode. 		*/
argument|switch (cp->nego_status) {  		case NS_SYNC: 			ncr_setsync (np, cp,
literal|0xe0
argument|); 			break;  		case NS_WIDE: 			ncr_setwide (np, cp,
literal|0
argument|); 			break;  		}; 		np->msgin [
literal|0
argument|] = M_NOOP; 		np->msgout[
literal|0
argument|] = M_NOOP; 		cp->nego_status =
literal|0
argument|; 		OUTL (nc_dsp,vtophys (&np->script->dispatch)); 		break;
argument|case SIR_NEGO_SYNC:
comment|/* 		**	Synchronous request message received. 		*/
argument|if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"sync msgin: "
argument|); 			(void) ncr_show_msg (np->msgin); 			printf (
literal|".\n"
argument|); 		};
comment|/* 		**	get requested values. 		*/
argument|chg =
literal|0
argument|; 		per = np->msgin[
literal|3
argument|]; 		ofs = np->msgin[
literal|4
argument|]; 		if (ofs==
literal|0
argument|) per=
literal|255
argument|;
comment|/* 		**      if target sends SDTR message, 		**              it CAN transfer synch. 		*/
argument|if (ofs) 			tp->inqdata[
literal|7
argument|] |= INQ7_SYNC;
comment|/* 		**	check values against driver limits. 		*/
argument|if (per< np->ns_sync) 			{chg =
literal|1
argument|; per = np->ns_sync;} 		if (per< tp->minsync) 			{chg =
literal|1
argument|; per = tp->minsync;} 		if (ofs> tp->maxoffs) 			{chg =
literal|1
argument|; ofs = tp->maxoffs;}
comment|/* 		**	Check against controller limits. 		*/
argument|fak = (
literal|4ul
argument|* per -
literal|1
argument|) / np->ns_sync -
literal|3
argument|; 		if (ofs&& (fak>
literal|7
argument|))   {chg =
literal|1
argument|; ofs =
literal|0
argument|;} 		if (!ofs) fak=
literal|7
argument|;  		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"sync: per=%d ofs=%d fak=%d chg=%d.\n"
argument|, 				per, ofs, fak, chg); 		}
argument|if (INB (HS_PRT) == HS_NEGOTIATE) { 			OUTB (HS_PRT, HS_BUSY); 			switch (cp->nego_status) {  			case NS_SYNC:
comment|/* 				**      This was an answer message 				*/
argument|if (chg) {
comment|/* 					**	Answer wasn't acceptable. 					*/
argument|ncr_setsync (np, cp,
literal|0xe0
argument|); 					OUTL (nc_dsp,vtophys (&np->script->msg_bad)); 				} else {
comment|/* 					**	Answer is ok. 					*/
argument|ncr_setsync (np, cp, (fak<<
literal|5
argument|)|ofs); 					OUTL (nc_dsp,vtophys (&np->script->clrack)); 				}; 				return;  			case NS_WIDE: 				ncr_setwide (np, cp,
literal|0
argument|); 				break; 			}; 		};
comment|/* 		**	It was a request. Set value and 		**      prepare an answer message 		*/
argument|ncr_setsync (np, cp, (fak<<
literal|5
argument|)|ofs);  		np->msgout[
literal|0
argument|] = M_EXTENDED; 		np->msgout[
literal|1
argument|] =
literal|3
argument|; 		np->msgout[
literal|2
argument|] = M_X_SYNC_REQ; 		np->msgout[
literal|3
argument|] = per; 		np->msgout[
literal|4
argument|] = ofs;  		np->msgin [
literal|0
argument|] = M_NOOP;  		cp->nego_status = NS_SYNC;  		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"sync msgout: "
argument|); 			(void) ncr_show_msg (np->msgin); 			printf (
literal|".\n"
argument|); 		} 		break;
argument|case SIR_NEGO_WIDE:
comment|/* 		**	Wide request message received. 		*/
argument|if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"wide msgin: "
argument|); 			(void) ncr_show_msg (np->msgin); 			printf (
literal|".\n"
argument|); 		};
comment|/* 		**	get requested values. 		*/
argument|chg  =
literal|0
argument|; 		wide = np->msgin[
literal|3
argument|];
comment|/* 		**      if target sends WDTR message, 		**              it CAN transfer wide. 		*/
argument|if (wide) 			tp->inqdata[
literal|7
argument|] |= INQ7_WIDE16;
comment|/* 		**	check values against driver limits. 		*/
argument|if (wide> tp->usrwide) 			{chg =
literal|1
argument|; wide = tp->usrwide;}  		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"wide: wide=%d chg=%d.\n"
argument|, wide, chg); 		}
argument|if (INB (HS_PRT) == HS_NEGOTIATE) { 			OUTB (HS_PRT, HS_BUSY); 			switch (cp->nego_status) {  			case NS_WIDE:
comment|/* 				**      This was an answer message 				*/
argument|if (chg) {
comment|/* 					**	Answer wasn't acceptable. 					*/
argument|ncr_setwide (np, cp,
literal|0
argument|); 					OUTL (nc_dsp,vtophys (&np->script->msg_bad)); 				} else {
comment|/* 					**	Answer is ok. 					*/
argument|ncr_setwide (np, cp, wide); 					OUTL (nc_dsp,vtophys (&np->script->clrack)); 				}; 				return;  			case NS_SYNC: 				ncr_setsync (np, cp,
literal|0xe0
argument|); 				break; 			}; 		};
comment|/* 		**	It was a request, set value and 		**      prepare an answer message 		*/
argument|ncr_setwide (np, cp, wide);  		np->msgout[
literal|0
argument|] = M_EXTENDED; 		np->msgout[
literal|1
argument|] =
literal|2
argument|; 		np->msgout[
literal|2
argument|] = M_X_WIDE_REQ; 		np->msgout[
literal|3
argument|] = wide;  		np->msgin [
literal|0
argument|] = M_NOOP;  		cp->nego_status = NS_WIDE;  		if (DEBUG_FLAGS& DEBUG_NEGO) { 			PRINT_ADDR(cp->xfer); 			printf (
literal|"wide msgout: "
argument|); 			(void) ncr_show_msg (np->msgin); 			printf (
literal|".\n"
argument|); 		} 		break;
comment|/*-------------------------------------------------------------------- ** **	Processing of special messages ** **-------------------------------------------------------------------- */
argument|case SIR_REJECT_RECEIVED:
comment|/*----------------------------------------------- 		** 		**	We received a M_REJECT message. 		** 		**----------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		printf (
literal|"M_REJECT received (%x:%x).\n"
argument|, 			(unsigned)np->lastmsg, np->msgout[
literal|0
argument|]); 		break;  	case SIR_REJECT_SENT:
comment|/*----------------------------------------------- 		** 		**	We received an unknown message 		** 		**----------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		printf (
literal|"M_REJECT sent for "
argument|); 		(void) ncr_show_msg (np->msgin); 		printf (
literal|".\n"
argument|); 		break;
comment|/*-------------------------------------------------------------------- ** **	Processing of special messages ** **-------------------------------------------------------------------- */
argument|case SIR_IGN_RESIDUE:
comment|/*----------------------------------------------- 		** 		**	We received an IGNORE RESIDUE message, 		**	which couldn't be handled by the script. 		** 		**----------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		printf (
literal|"M_IGN_RESIDUE received, but not yet implemented.\n"
argument|); 		break;  	case SIR_MISSING_SAVE:
comment|/*----------------------------------------------- 		** 		**	We received an DISCONNECT message, 		**	but the datapointer wasn't saved before. 		** 		**----------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		printf (
literal|"M_DISCONNECT received, but datapointer not saved:\n"
literal|"\tdata=%x save=%x goal=%x.\n"
argument|, 			(unsigned) INL (nc_temp), 			(unsigned) np->header.savep, 			(unsigned) np->header.goalp); 		break;
comment|/*-------------------------------------------------------------------- ** **	Processing of a "S_QUEUE_FULL" status. ** **	The current command has been rejected, **	because there are too many in the command queue. **	We have started too many commands for that target. ** **	If possible, reinsert at head of queue. **	Stall queue until there are no disconnected jobs **	(ncr is REALLY idle). Then restart processing. ** **	We should restart the current job after the controller **	has become idle. But this is not yet implemented. ** **-------------------------------------------------------------------- */
argument|case SIR_STALL_QUEUE:
comment|/*----------------------------------------------- 		** 		**	Stall the start queue. 		** 		**----------------------------------------------- 		*/
argument|PRINT_ADDR(cp->xfer); 		printf (
literal|"queue full.\n"
argument|);  		np->script->start1[
literal|0
argument|] =  SCR_INT;
comment|/* 		**	Try to disable tagged transfers. 		*/
argument|ncr_setmaxtags (&np->target[target],
literal|0
argument|);
comment|/* 		** @QUEUE@ 		** 		**	Should update the launch field of the 		**	current job to be able to restart it. 		**	Then prepend it to the start queue. 		*/
comment|/* fall through */
argument|case SIR_STALL_RESTART:
comment|/*----------------------------------------------- 		** 		**	Enable selecting again, 		**	if NO disconnected jobs. 		** 		**----------------------------------------------- 		*/
comment|/* 		**	Look for a disconnected job. 		*/
argument|cp =&np->ccb; 		while (cp&& cp->host_status != HS_DISCONNECT) 			cp = cp->link_ccb;
comment|/* 		**	if there is one, ... 		*/
argument|if (cp) {
comment|/* 			**	wait for reselection 			*/
argument|OUTL (nc_dsp, vtophys (&np->script->reselect)); 			return; 		};
comment|/* 		**	else remove the interrupt. 		*/
argument|printf (
literal|"%s: queue empty.\n"
argument|, ncr_name (np)); 		np->script->start1[
literal|0
argument|] =  SCR_INT ^ IFFALSE (
literal|0
argument|); 		break; 	};  out: 	OUTB (nc_dcntl, (STD|NOCOM)); }
comment|/*========================================================== ** ** **	Aquire a control block ** ** **========================================================== */
argument|static	ccb_p ncr_get_ccb 	(ncb_p np, u_long flags, u_long target, u_long lun) { 	lcb_p lp; 	ccb_p cp = (ccb_p )
literal|0
argument|;
comment|/* 	**	Lun structure available ? 	*/
argument|lp = np->target[target].lp[lun]; 	if (lp) 		cp = lp->next_ccb;
comment|/* 	**	Look for free CCB 	*/
argument|while (cp&& cp->magic) cp = cp->next_ccb;
comment|/* 	**	if nothing available, take the default. 	*/
argument|if (!cp) cp =&np->ccb;
comment|/* 	**	Wait until available. 	*/
argument|while (cp->magic) { 		if (flags& SCSI_NOSLEEP) break; 		if (tsleep ((caddr_t)cp, PRIBIO|PCATCH,
literal|"ncr"
argument|,
literal|0
argument|)) 			break; 	};  	if (cp->magic) 		return ((ccb_p)
literal|0
argument|);  	cp->magic =
literal|1
argument|; 	return (cp); }
comment|/*========================================================== ** ** **	Release one control block ** ** **========================================================== */
argument|void ncr_free_ccb (ncb_p np, ccb_p cp, int flags) {
comment|/* 	**    sanity 	*/
argument|if (!cp) return;  	cp -> host_status = HS_IDLE; 	cp -> magic =
literal|0
argument|; 	if (cp ==&np->ccb) 		wakeup ((caddr_t) cp); }
comment|/*========================================================== ** ** **      Allocation of resources for Targets/Luns/Tags. ** ** **========================================================== */
argument|static	void ncr_alloc_ccb (ncb_p np, struct scsi_xfer * xp) { 	tcb_p tp; 	lcb_p lp; 	ccb_p cp;  	u_long	target; 	u_long	lun;  	if (!np) return; 	if (!xp) return;  	target = xp->TARGET; 	lun    = xp->LUN;  	if (target>=MAX_TARGET) return; 	if (lun>=MAX_LUN   ) return;  	tp=&np->target[target];  	if (!tp->jump_tcb.l_cmd) {
comment|/* 		**	initialize it. 		*/
argument|tp->jump_tcb.l_cmd   = (SCR_JUMP^IFFALSE (DATA (
literal|0x80
argument|+ target))); 		tp->jump_tcb.l_paddr = np->jump_tcb.l_paddr;  		tp->getscr[
literal|0
argument|] = SCR_COPY (
literal|1
argument|); 		tp->getscr[
literal|1
argument|] = vtophys (&tp->sval); 		tp->getscr[
literal|2
argument|] = np->paddr + offsetof (struct ncr_reg, nc_sxfer); 		tp->getscr[
literal|3
argument|] = SCR_COPY (
literal|1
argument|); 		tp->getscr[
literal|4
argument|] = vtophys (&tp->wval); 		tp->getscr[
literal|5
argument|] = np->paddr + offsetof (struct ncr_reg, nc_scntl3);  		assert (( (offsetof(struct ncr_reg, nc_sxfer) ^  			offsetof(struct tcb    , sval    ))&
literal|3
argument|) ==
literal|0
argument|); 		assert (( (offsetof(struct ncr_reg, nc_scntl3) ^  			offsetof(struct tcb    , wval    ))&
literal|3
argument|) ==
literal|0
argument|);  		tp->call_lun.l_cmd   = (SCR_CALL); 		tp->call_lun.l_paddr = vtophys (&np->script->resel_lun);  		tp->jump_lcb.l_cmd   = (SCR_JUMP); 		tp->jump_lcb.l_paddr = vtophys (&np->script->abort); 		np->jump_tcb.l_paddr = vtophys (&tp->jump_tcb);  		ncr_setmaxtags (tp, SCSI_NCR_MAX_TAGS); 	}
comment|/* 	**	Logic unit control block 	*/
argument|lp = tp->lp[lun]; 	if (!lp) {
comment|/* 		**	Allocate a lcb 		*/
argument|lp = (lcb_p) malloc (sizeof (struct lcb), M_DEVBUF, M_NOWAIT); 		if (!lp) return;
comment|/* 		**	Initialize it 		*/
argument|bzero (lp, sizeof (*lp)); 		lp->jump_lcb.l_cmd   = (SCR_JUMP ^ IFFALSE (DATA (lun))); 		lp->jump_lcb.l_paddr = tp->jump_lcb.l_paddr;  		lp->call_tag.l_cmd   = (SCR_CALL); 		lp->call_tag.l_paddr = vtophys (&np->script->resel_tag);  		lp->jump_ccb.l_cmd   = (SCR_JUMP); 		lp->jump_ccb.l_paddr = vtophys (&np->script->aborttag);  		lp->actlink =
literal|1
argument|;
comment|/* 		**   Link into Lun-Chain 		*/
argument|tp->jump_lcb.l_paddr = vtophys (&lp->jump_lcb); 		tp->lp[lun] = lp;  	}
comment|/* 	**	Limit possible number of ccbs. 	** 	**	If tagged command queueing is enabled, 	**	can use more than one ccb. 	*/
argument|if (np->actccbs>= MAX_START-
literal|2
argument|) return; 	if (lp->actccbs&& (lp->actccbs>= lp->reqccbs)) 		return;
comment|/* 	**	Allocate a ccb 	*/
argument|cp = (ccb_p) malloc (sizeof (struct ccb), M_DEVBUF, M_NOWAIT);  	if (!cp) 		return;  	if (DEBUG_FLAGS& DEBUG_ALLOC) { 		PRINT_ADDR(xp); 		printf (
literal|"new ccb @%x.\n"
argument|, (unsigned) cp); 	}
comment|/* 	**	Count it 	*/
argument|lp->actccbs++; 	np->actccbs++;
comment|/* 	**	Initialize it. 	*/
argument|bzero (cp, sizeof (*cp));
comment|/* 	**	link in reselect chain. 	*/
argument|cp->jump_ccb.l_cmd   = SCR_JUMP; 	cp->jump_ccb.l_paddr = lp->jump_ccb.l_paddr; 	lp->jump_ccb.l_paddr = vtophys(&cp->jump_ccb); 	cp->call_tmp.l_cmd   = SCR_CALL; 	cp->call_tmp.l_paddr = vtophys(&np->script->resel_tmp);
comment|/* 	**	link in wakeup chain 	*/
argument|cp->link_ccb      = np->ccb.link_ccb; 	np->ccb.link_ccb  = cp;
comment|/* 	**	Link into CCB-Chain 	*/
argument|cp->next_ccb	= lp->next_ccb; 	lp->next_ccb	= cp; }
comment|/*========================================================== ** ** **	Announce the number of ccbs/tags to the scsi driver. ** ** **========================================================== */
argument|static void ncr_opennings (ncb_p np, lcb_p lp, struct scsi_xfer * xp) {
ifndef|#
directive|ifndef
name|ANCIENT
comment|/* 	**	want to reduce the number ... 	*/
argument|if (lp->actlink> lp->reqlink) {
comment|/* 		**	Try to  reduce the count. 		**	We assume to run at splbio .. 		*/
argument|u_char diff = lp->actlink - lp->reqlink;  		if (!diff) return;  		if (diff> xp->sc_link->opennings) 			diff = xp->sc_link->opennings;  		xp->sc_link->opennings	-= diff; 		lp->actlink		-= diff; 		if (DEBUG_FLAGS& DEBUG_TAGS) 			printf (
literal|"%s: actlink: diff=%d, new=%d, req=%d\n"
argument|, 				ncr_name(np), diff, lp->actlink, lp->reqlink); 		return; 	};
comment|/* 	**	want to increase the number ? 	*/
argument|if (lp->reqlink> lp->actlink) { 		u_char diff = lp->reqlink - lp->actlink;  		xp->sc_link->opennings	+= diff; 		lp->actlink		+= diff; 		wakeup ((caddr_t) xp->sc_link); 		if (DEBUG_FLAGS& DEBUG_TAGS) 			printf (
literal|"%s: actlink: diff=%d, new=%d, req=%d\n"
argument|, 				ncr_name(np), diff, lp->actlink, lp->reqlink); 	};
endif|#
directive|endif
argument|}
comment|/*========================================================== ** ** **	Build Scatter Gather Block ** ** **========================================================== ** **	The transfer area may be scattered among **	several non adjacent physical pages. ** **	We may use MAX_SCATTER blocks. ** **---------------------------------------------------------- */
argument|static	int	ncr_scatter 	(struct dsb* phys, vm_offset_t vaddr, vm_size_t datalen) { 	u_long	paddr
argument_list|,
argument|pnext;  	u_short	segment  =
literal|0
argument|; 	u_long	segsize
argument_list|,
argument|segaddr; 	u_long	size
argument_list|,
argument|csize    =
literal|0
argument|; 	u_long	chunk = MAX_SIZE; 	int	free;  	bzero (&phys->data, sizeof (phys->data)); 	if (!datalen) return (
literal|0
argument|);  	paddr = vtophys (vaddr);
comment|/* 	**	insert extra break points at a distance of chunk. 	**	We try to reduce the number of interrupts due to 	**	unexpected phase changes due to disconnects. 	**	A typical harddisk may disconnect before ANY block. 	**	If we want to avoid unexpected phase changes at all 	**	we have to use a break point every 512 bytes. 	**	Of course the number of scatter/gather blocks is 	**	limited. 	*/
argument|free = MAX_SCATTER -
literal|1
argument|;  	if (vaddr& (NBPG-
literal|1
argument|)) free -= datalen / NBPG;  	if (free>
literal|1
argument|) 		while ((chunk * free>=
literal|2
argument|* datalen)&& (chunk>=
literal|1024
argument|)) 			chunk /=
literal|2
argument|;  	if(DEBUG_FLAGS& DEBUG_SCATTER) 		printf(
literal|"ncr?:\tscattering virtual=0x%x size=%d chunk=%d.\n"
argument|, 			(unsigned) vaddr, (unsigned) datalen, (unsigned) chunk);
comment|/* 	**   Build data descriptors. 	*/
argument|while (datalen&& (segment< MAX_SCATTER)) {
comment|/* 		**	this segment is empty 		*/
argument|segsize =
literal|0
argument|; 		segaddr = paddr; 		pnext   = paddr;  		if (!csize) csize = chunk;  		while ((datalen)&& (paddr == pnext)&& (csize)) {
comment|/* 			**	continue this segment 			*/
argument|pnext = (paddr& (~(NBPG -
literal|1
argument|))) + NBPG;
comment|/* 			**	Compute max size 			*/
argument|size = pnext - paddr;
comment|/* page size */
argument|if (size> datalen) size = datalen;
comment|/* data size */
argument|if (size> csize  ) size = csize  ;
comment|/* chunksize */
argument|segsize += size; 			vaddr   += size; 			csize   -= size; 			datalen -= size; 			paddr    = vtophys (vaddr); 		};  		if(DEBUG_FLAGS& DEBUG_SCATTER) 			printf (
literal|"\tseg #%d  addr=%x  size=%d  (rest=%d).\n"
argument|, 			segment, 			(unsigned) segaddr, 			(unsigned) segsize, 			(unsigned) datalen);  		phys->data[segment].addr = segaddr; 		phys->data[segment].size = segsize; 		segment++; 	}  	if (datalen) { 		printf(
literal|"ncr?: scatter/gather failed (residue=%d).\n"
argument|, 			(unsigned) datalen); 		return (-
literal|1
argument|); 	};  	return (segment); }
comment|/*========================================================== ** ** **	Test the pci bus snoop logic :-( ** **	Has to be called with interrupts disabled. ** ** **========================================================== */
argument|static int ncr_snooptest (struct ncb* np) { 	u_long	ncr_rd
argument_list|,
argument|ncr_wr
argument_list|,
argument|ncr_bk
argument_list|,
argument|host_rd
argument_list|,
argument|host_wr
argument_list|,
argument|pc
argument_list|,
argument|err=
literal|0
argument|;
comment|/* 	**	init 	*/
argument|pc  = vtophys (&np->script->snooptest); 	host_wr =
literal|1
argument|; 	ncr_wr  =
literal|2
argument|;
comment|/* 	**	Set memory and register. 	*/
argument|ncr_cache = host_wr; 	OUTL (nc_temp, ncr_wr);
comment|/* 	**	Start script (exchange values) 	*/
argument|OUTL (nc_dsp, pc);
comment|/* 	**	Wait 'til done 	*/
argument|while (!(INB(nc_istat)& (INTF|SIP|DIP)));
comment|/* 	**	Read memory and register. 	*/
argument|host_rd = ncr_cache; 	ncr_rd  = INL (nc_scratcha); 	ncr_bk  = INL (nc_temp);
comment|/* 	**	Reset ncr chip 	*/
argument|OUTB (nc_istat,  SRST); 	OUTB (nc_istat,
literal|0
argument|);
comment|/* 	**	Show results. 	*/
argument|if (host_wr != ncr_rd) { 		printf (
literal|"CACHE TEST FAILED: host wrote %d, ncr read %d.\n"
argument|, 			(int) host_wr, (int) ncr_rd); 		err |=
literal|1
argument|; 	}; 	if (host_rd != ncr_wr) { 		printf (
literal|"CACHE TEST FAILED: ncr wrote %d, host read %d.\n"
argument|, 			(int) ncr_wr, (int) host_rd); 		err |=
literal|2
argument|; 	}; 	if (ncr_bk != ncr_wr) { 		printf (
literal|"CACHE TEST FAILED: ncr wrote %d, read back %d.\n"
argument|, 			(int) ncr_wr, (int) ncr_bk); 		err |=
literal|4
argument|; 	}; 	return (err); }
comment|/*========================================================== ** ** **	Profiling the drivers and targets performance. ** ** **========================================================== */
comment|/* **	Compute the difference in milliseconds. **/
argument|static	int ncr_delta (struct timeval * from, struct timeval * to) { 	if (!from->tv_sec) return (-
literal|1
argument|); 	if (!to  ->tv_sec) return (-
literal|2
argument|); 	return ( (to->tv_sec  - from->tv_sec  -
literal|2
argument|)*
literal|1000
argument|+ 		+(to->tv_usec - from->tv_usec +
literal|2000000
argument|)/
literal|1000
argument|); }
define|#
directive|define
name|PROFILE
value|cp->phys.header.stamp
argument|static	void ncb_profile (ncb_p np, ccb_p cp) { 	int co
argument_list|,
argument|da
argument_list|,
argument|st
argument_list|,
argument|en
argument_list|,
argument|di
argument_list|,
argument|se
argument_list|,
argument|post
argument_list|,
argument|work
argument_list|,
argument|disc; 	u_long diff;  	PROFILE.end = time;  	st = ncr_delta (&PROFILE.start,&PROFILE.status); 	if (st<
literal|0
argument|) return;
comment|/* status  not reached  */
argument|da = ncr_delta (&PROFILE.start,&PROFILE.data); 	if (da<
literal|0
argument|) return;
comment|/* No data transfer phase */
argument|co = ncr_delta (&PROFILE.start,&PROFILE.command); 	if (co<
literal|0
argument|) return;
comment|/* command not executed */
argument|en = ncr_delta (&PROFILE.start,&PROFILE.end)
argument_list|,
argument|di = ncr_delta (&PROFILE.start,&PROFILE.disconnect)
argument_list|,
argument|se = ncr_delta (&PROFILE.start,&PROFILE.select); 	post = en - st;
comment|/* 	**	@PROFILE@  Disconnect time invalid if multiple disconnects 	*/
argument|if (di>=
literal|0
argument|) disc = se-di; else  disc =
literal|0
argument|;  	work = (st - co) - disc;  	diff = (np->disc_phys - np->disc_ref)&
literal|0xff
argument|; 	np->disc_ref += diff;  	np->profile.num_trans	+=
literal|1
argument|; 	if (cp->xfer) 	np->profile.num_bytes	+= cp->xfer->datalen; 	np->profile.num_disc	+= diff; 	np->profile.ms_setup	+= co; 	np->profile.ms_data	+= work; 	np->profile.ms_disc	+= disc; 	np->profile.ms_post	+= post; }
undef|#
directive|undef
name|PROFILE
comment|/*========================================================== ** ** **	Device lookup. ** **	@GENSCSI@ should be integrated to scsiconf.c ** ** **========================================================== */
ifndef|#
directive|ifndef
name|NEW_SCSICONF
argument|struct table_entry { 	char *	manufacturer; 	char *	model; 	char *	version; 	u_long	info; };  static struct table_entry device_tab[] = { 	{
literal|"SONY"
argument_list|,
literal|"SDT-5000"
argument_list|,
literal|"3.17"
argument_list|,
argument|QUIRK_NOMSG}
argument_list|,
argument|{
literal|"WangDAT"
argument_list|,
literal|"Model 2600"
argument_list|,
literal|"01.7"
argument_list|,
argument|QUIRK_NOMSG}
argument_list|,
argument|{
literal|"WangDAT"
argument_list|,
literal|"Model 3200"
argument_list|,
literal|"02.2"
argument_list|,
argument|QUIRK_NOMSG}
argument_list|,
argument|{
literal|"WangDAT"
argument_list|,
literal|"Model 1300"
argument_list|,
literal|"02.4"
argument_list|,
argument|QUIRK_NOMSG}
argument_list|,
argument|{
literal|""
argument_list|,
literal|""
argument_list|,
literal|""
argument_list|,
literal|0
argument|}
comment|/* catch all: must be last entry. */
argument|};  static u_long ncr_lookup(char * id) { 	struct table_entry * p = device_tab; 	char *d
argument_list|,
argument|*r
argument_list|,
argument|c;  	for (;;p++) {  		d = id+
literal|8
argument|; 		r = p->manufacturer; 		while ((c=*r++)) if (c!=*d++) break; 		if (c) continue;  		d = id+
literal|16
argument|; 		r = p->model; 		while ((c=*r++)) if (c!=*d++) break; 		if (c) continue;  		d = id+
literal|32
argument|; 		r = p->version; 		while ((c=*r++)) if (c!=*d++) break; 		if (c) continue;  		return (p->info); 	} }
endif|#
directive|endif
comment|/*========================================================== ** **	Determine the ncr's clock frequency. **	This is important for the negotiation **	of the synchronous transfer rate. ** **========================================================== ** **	Note: we have to return the correct value. **	THERE IS NO SAVE DEFAULT VALUE. ** **	We assume that all NCR based boards are delivered **	with a 40Mhz clock. Because we have to divide **	by an integer value greater than 3, only clock **	frequencies of 40Mhz (/4) or 50MHz (/5) permit **	the FAST-SCSI rate of 10MHz. ** **---------------------------------------------------------- */
ifndef|#
directive|ifndef
name|NCR_CLOCK
define|#
directive|define
name|NCR_CLOCK
value|40
endif|#
directive|endif
comment|/* NCR_CLOCK */
argument|static void ncr_getclock (ncb_p np) { 	u_char	tbl[
literal|5
argument|] = {
literal|6
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|6
argument|}; 	u_char	f; 	u_char	ns_clock = (
literal|1000
argument|/NCR_CLOCK);
comment|/* 	**	Compute the best value for scntl3. 	*/
argument|f = (
literal|2
argument|* MIN_SYNC_PD -
literal|1
argument|) / ns_clock; 	if (!f ) f=
literal|1
argument|; 	if (f>
literal|4
argument|) f=
literal|4
argument|; 	np -> ns_sync = (ns_clock * tbl[f]) /
literal|2
argument|; 	np -> rv_scntl3 = f<<
literal|4
argument|;  	f = (
literal|2
argument|* MIN_ASYNC_PD -
literal|1
argument|) / ns_clock; 	if (!f ) f=
literal|1
argument|; 	if (f>
literal|4
argument|) f=
literal|4
argument|; 	np -> ns_async = (ns_clock * tbl[f]) /
literal|2
argument|; 	np -> rv_scntl3 |= f; 	if (DEBUG_FLAGS& DEBUG_TIMING) 		printf (
literal|"%s: sclk=%d async=%d sync=%d (ns) scntl3=0x%x\n"
argument|, 		ncr_name (np), ns_clock, np->ns_async, np->ns_sync, np->rv_scntl3); }
end_block

begin_comment
comment|/*=========================================================================*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

