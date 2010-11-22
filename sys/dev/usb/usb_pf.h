begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from the Stanford/CMU enet packet filter,  * (net/enet.c) distributed as part of 4.3BSD, and code contributed  * to Berkeley by Steven McCanne and Van Jacobson both of Lawrence  * Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_USB_PF_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_USB_PF_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int32_t
name|usbpf_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|usbpf_u_int32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|usbpf_int64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|usbpf_u_int64
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|usbpf_if
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Alignment macros.  USBPF_WORDALIGN rounds up to the next  * even multiple of USBPF_ALIGNMENT.  */
end_comment

begin_define
define|#
directive|define
name|USBPF_ALIGNMENT
value|sizeof(long)
end_define

begin_define
define|#
directive|define
name|USBPF_WORDALIGN
parameter_list|(
name|x
parameter_list|)
value|(((x)+(USBPF_ALIGNMENT-1))&~(USBPF_ALIGNMENT-1))
end_define

begin_comment
comment|/*  * The instruction encodings.  */
end_comment

begin_comment
comment|/* instruction classes */
end_comment

begin_define
define|#
directive|define
name|USBPF_CLASS
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x07)
end_define

begin_define
define|#
directive|define
name|USBPF_LD
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_LDX
value|0x01
end_define

begin_define
define|#
directive|define
name|USBPF_ST
value|0x02
end_define

begin_define
define|#
directive|define
name|USBPF_STX
value|0x03
end_define

begin_define
define|#
directive|define
name|USBPF_ALU
value|0x04
end_define

begin_define
define|#
directive|define
name|USBPF_JMP
value|0x05
end_define

begin_define
define|#
directive|define
name|USBPF_RET
value|0x06
end_define

begin_define
define|#
directive|define
name|USBPF_MISC
value|0x07
end_define

begin_comment
comment|/* ld/ldx fields */
end_comment

begin_define
define|#
directive|define
name|USBPF_SIZE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
end_define

begin_define
define|#
directive|define
name|USBPF_W
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_H
value|0x08
end_define

begin_define
define|#
directive|define
name|USBPF_B
value|0x10
end_define

begin_define
define|#
directive|define
name|USBPF_MODE
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xe0)
end_define

begin_define
define|#
directive|define
name|USBPF_IMM
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_ABS
value|0x20
end_define

begin_define
define|#
directive|define
name|USBPF_IND
value|0x40
end_define

begin_define
define|#
directive|define
name|USBPF_MEM
value|0x60
end_define

begin_define
define|#
directive|define
name|USBPF_LEN
value|0x80
end_define

begin_define
define|#
directive|define
name|USBPF_MSH
value|0xa0
end_define

begin_comment
comment|/* alu/jmp fields */
end_comment

begin_define
define|#
directive|define
name|USBPF_OP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf0)
end_define

begin_define
define|#
directive|define
name|USBPF_ADD
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_SUB
value|0x10
end_define

begin_define
define|#
directive|define
name|USBPF_MUL
value|0x20
end_define

begin_define
define|#
directive|define
name|USBPF_DIV
value|0x30
end_define

begin_define
define|#
directive|define
name|USBPF_OR
value|0x40
end_define

begin_define
define|#
directive|define
name|USBPF_AND
value|0x50
end_define

begin_define
define|#
directive|define
name|USBPF_LSH
value|0x60
end_define

begin_define
define|#
directive|define
name|USBPF_RSH
value|0x70
end_define

begin_define
define|#
directive|define
name|USBPF_NEG
value|0x80
end_define

begin_define
define|#
directive|define
name|USBPF_JA
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_JEQ
value|0x10
end_define

begin_define
define|#
directive|define
name|USBPF_JGT
value|0x20
end_define

begin_define
define|#
directive|define
name|USBPF_JGE
value|0x30
end_define

begin_define
define|#
directive|define
name|USBPF_JSET
value|0x40
end_define

begin_define
define|#
directive|define
name|USBPF_SRC
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x08)
end_define

begin_define
define|#
directive|define
name|USBPF_K
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_X
value|0x08
end_define

begin_comment
comment|/* ret - USBPF_K and USBPF_X also apply */
end_comment

begin_define
define|#
directive|define
name|USBPF_RVAL
parameter_list|(
name|code
parameter_list|)
value|((code)& 0x18)
end_define

begin_define
define|#
directive|define
name|USBPF_A
value|0x10
end_define

begin_comment
comment|/* misc */
end_comment

begin_define
define|#
directive|define
name|USBPF_MISCOP
parameter_list|(
name|code
parameter_list|)
value|((code)& 0xf8)
end_define

begin_define
define|#
directive|define
name|USBPF_TAX
value|0x00
end_define

begin_define
define|#
directive|define
name|USBPF_TXA
value|0x80
end_define

begin_comment
comment|/*  * The instruction data structure.  */
end_comment

begin_struct
struct|struct
name|usbpf_insn
block|{
name|u_short
name|code
decl_stmt|;
name|u_char
name|jt
decl_stmt|;
name|u_char
name|jf
decl_stmt|;
name|usbpf_u_int32
name|k
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Descriptor associated with each open uff file.  */
end_comment

begin_struct
struct|struct
name|usbpf_d
block|{
name|LIST_ENTRY
argument_list|(
argument|usbpf_d
argument_list|)
name|ud_next
expr_stmt|;
comment|/* Linked list of descriptors */
comment|/* 	 * Buffer slots: two memory buffers store the incoming packets. 	 *   The model has three slots.  Sbuf is always occupied. 	 *   sbuf (store) - Receive interrupt puts packets here. 	 *   hbuf (hold) - When sbuf is full, put buffer here and 	 *                 wakeup read (replace sbuf with fbuf). 	 *   fbuf (free) - When read is done, put buffer here. 	 * On receiving, if sbuf is full and fbuf is 0, packet is dropped. 	 */
name|caddr_t
name|ud_sbuf
decl_stmt|;
comment|/* store slot */
name|caddr_t
name|ud_hbuf
decl_stmt|;
comment|/* hold slot */
name|caddr_t
name|ud_fbuf
decl_stmt|;
comment|/* free slot */
name|int
name|ud_slen
decl_stmt|;
comment|/* current length of store buffer */
name|int
name|ud_hlen
decl_stmt|;
comment|/* current length of hold buffer */
name|int
name|ud_bufsize
decl_stmt|;
comment|/* absolute length of buffers */
name|struct
name|usbpf_if
modifier|*
name|ud_bif
decl_stmt|;
comment|/* interface descriptor */
name|u_long
name|ud_rtout
decl_stmt|;
comment|/* Read timeout in 'ticks' */
name|struct
name|usbpf_insn
modifier|*
name|ud_rfilter
decl_stmt|;
comment|/* read filter code */
name|struct
name|usbpf_insn
modifier|*
name|ud_wfilter
decl_stmt|;
comment|/* write filter code */
name|void
modifier|*
name|ud_bfilter
decl_stmt|;
comment|/* binary filter code */
name|u_int64_t
name|ud_rcount
decl_stmt|;
comment|/* number of packets received */
name|u_int64_t
name|ud_dcount
decl_stmt|;
comment|/* number of packets dropped */
name|u_char
name|ud_promisc
decl_stmt|;
comment|/* true if listening promiscuously */
name|u_char
name|ud_state
decl_stmt|;
comment|/* idle, waiting, or timed out */
name|u_char
name|ud_immediate
decl_stmt|;
comment|/* true to return on packet arrival */
name|int
name|ud_hdrcmplt
decl_stmt|;
comment|/* false to fill in src lladdr automatically */
name|int
name|ud_direction
decl_stmt|;
comment|/* select packet direction */
name|int
name|ud_tstamp
decl_stmt|;
comment|/* select time stamping function */
name|int
name|ud_feedback
decl_stmt|;
comment|/* true to feed back sent packets */
name|int
name|ud_async
decl_stmt|;
comment|/* non-zero if packet reception should generate signal */
name|int
name|ud_sig
decl_stmt|;
comment|/* signal to send upon packet reception */
name|struct
name|sigio
modifier|*
name|ud_sigio
decl_stmt|;
comment|/* information for async I/O */
name|struct
name|selinfo
name|ud_sel
decl_stmt|;
comment|/* bsd select info */
name|struct
name|mtx
name|ud_mtx
decl_stmt|;
comment|/* mutex for this descriptor */
name|struct
name|callout
name|ud_callout
decl_stmt|;
comment|/* for USBPF timeouts with select */
name|struct
name|label
modifier|*
name|ud_label
decl_stmt|;
comment|/* MAC label for descriptor */
name|u_int64_t
name|ud_fcount
decl_stmt|;
comment|/* number of packets which matched filter */
name|pid_t
name|ud_pid
decl_stmt|;
comment|/* PID which created descriptor */
name|int
name|ud_locked
decl_stmt|;
comment|/* true if descriptor is locked */
name|u_int
name|ud_bufmode
decl_stmt|;
comment|/* Current buffer mode. */
name|u_int64_t
name|ud_wcount
decl_stmt|;
comment|/* number of packets written */
name|u_int64_t
name|ud_wfcount
decl_stmt|;
comment|/* number of packets that matched write filter */
name|u_int64_t
name|ud_wdcount
decl_stmt|;
comment|/* number of packets dropped during a write */
name|u_int64_t
name|ud_zcopy
decl_stmt|;
comment|/* number of zero copy operations */
name|u_char
name|ud_compat32
decl_stmt|;
comment|/* 32-bit stream on LP64 system */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USBPFD_LOCK
parameter_list|(
name|ud
parameter_list|)
value|mtx_lock(&(ud)->ud_mtx)
end_define

begin_define
define|#
directive|define
name|USBPFD_UNLOCK
parameter_list|(
name|ud
parameter_list|)
value|mtx_unlock(&(ud)->ud_mtx)
end_define

begin_define
define|#
directive|define
name|USBPFD_LOCK_ASSERT
parameter_list|(
name|ud
parameter_list|)
value|mtx_assert(&(ud)->ud_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * Descriptor associated with each attached hardware interface.  */
end_comment

begin_struct
struct|struct
name|usbpf_if
block|{
name|LIST_ENTRY
argument_list|(
argument|usbpf_if
argument_list|)
name|uif_next
expr_stmt|;
comment|/* list of all interfaces */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|usbpf_d
argument_list|)
name|uif_dlist
expr_stmt|;
comment|/* descriptor list */
name|u_int
name|uif_hdrlen
decl_stmt|;
comment|/* length of link header */
name|struct
name|usb_bus
modifier|*
name|uif_ubus
decl_stmt|;
comment|/* corresponding interface */
name|struct
name|mtx
name|uif_mtx
decl_stmt|;
comment|/* mutex for interface */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USBPFIF_LOCK
parameter_list|(
name|uif
parameter_list|)
value|mtx_lock(&(uif)->uif_mtx)
end_define

begin_define
define|#
directive|define
name|USBPFIF_UNLOCK
parameter_list|(
name|uif
parameter_list|)
value|mtx_unlock(&(uif)->uif_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure prepended to each packet.  */
end_comment

begin_struct
struct|struct
name|usbpf_ts
block|{
name|usbpf_int64
name|ut_sec
decl_stmt|;
comment|/* seconds */
name|usbpf_u_int64
name|ut_frac
decl_stmt|;
comment|/* fraction */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbpf_xhdr
block|{
name|struct
name|usbpf_ts
name|uh_tstamp
decl_stmt|;
comment|/* time stamp */
name|usbpf_u_int32
name|uh_caplen
decl_stmt|;
comment|/* length of captured portion */
name|usbpf_u_int32
name|uh_datalen
decl_stmt|;
comment|/* original length of packet */
name|u_short
name|uh_hdrlen
decl_stmt|;
comment|/* length of uff header (this struct 					   plus alignment padding) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USBPF_BUFMODE_BUFFER
value|1
end_define

begin_comment
comment|/* Kernel buffers with read(). */
end_comment

begin_define
define|#
directive|define
name|USBPF_BUFMODE_ZBUF
value|2
end_define

begin_comment
comment|/* Zero-copy buffers. */
end_comment

begin_struct
struct|struct
name|usbpf_pkthdr
block|{
name|int
name|up_busunit
decl_stmt|;
comment|/* Host controller unit number */
name|u_char
name|up_address
decl_stmt|;
comment|/* USB device address */
name|u_char
name|up_endpoint
decl_stmt|;
comment|/* USB endpoint */
name|u_char
name|up_type
decl_stmt|;
comment|/* points SUBMIT / DONE */
name|u_char
name|up_xfertype
decl_stmt|;
comment|/* Transfer type */
name|u_int32_t
name|up_flags
decl_stmt|;
comment|/* Transfer flags */
define|#
directive|define
name|USBPF_FLAG_FORCE_SHORT_XFER
value|(1<< 0)
define|#
directive|define
name|USBPF_FLAG_SHORT_XFER_OK
value|(1<< 1)
define|#
directive|define
name|USBPF_FLAG_SHORT_FRAMES_OK
value|(1<< 2)
define|#
directive|define
name|USBPF_FLAG_PIPE_BOF
value|(1<< 3)
define|#
directive|define
name|USBPF_FLAG_PROXY_BUFFER
value|(1<< 4)
define|#
directive|define
name|USBPF_FLAG_EXT_BUFFER
value|(1<< 5)
define|#
directive|define
name|USBPF_FLAG_MANUAL_STATUS
value|(1<< 6)
define|#
directive|define
name|USBPF_FLAG_NO_PIPE_OK
value|(1<< 7)
define|#
directive|define
name|USBPF_FLAG_STALL_PIPE
value|(1<< 8)
name|u_int32_t
name|up_status
decl_stmt|;
comment|/* Transfer status */
define|#
directive|define
name|USBPF_STATUS_OPEN
value|(1<< 0)
define|#
directive|define
name|USBPF_STATUS_TRANSFERRING
value|(1<< 1)
define|#
directive|define
name|USBPF_STATUS_DID_DMA_DELAY
value|(1<< 2)
define|#
directive|define
name|USBPF_STATUS_DID_CLOSE
value|(1<< 3)
define|#
directive|define
name|USBPF_STATUS_DRAINING
value|(1<< 4)
define|#
directive|define
name|USBPF_STATUS_STARTED
value|(1<< 5)
define|#
directive|define
name|USBPF_STATUS_BW_RECLAIMED
value|(1<< 6)
define|#
directive|define
name|USBPF_STATUS_CONTROL_XFR
value|(1<< 7)
define|#
directive|define
name|USBPF_STATUS_CONTROL_HDR
value|(1<< 8)
define|#
directive|define
name|USBPF_STATUS_CONTROL_ACT
value|(1<< 9)
define|#
directive|define
name|USBPF_STATUS_CONTROL_STALL
value|(1<< 10)
define|#
directive|define
name|USBPF_STATUS_SHORT_FRAMES_OK
value|(1<< 11)
define|#
directive|define
name|USBPF_STATUS_SHORT_XFER_OK
value|(1<< 12)
if|#
directive|if
name|USB_HAVE_BUSDMA
define|#
directive|define
name|USBPF_STATUS_BDMA_ENABLE
value|(1<< 13)
define|#
directive|define
name|USBPF_STATUS_BDMA_NO_POST_SYNC
value|(1<< 14)
define|#
directive|define
name|USBPF_STATUS_BDMA_SETUP
value|(1<< 15)
endif|#
directive|endif
define|#
directive|define
name|USBPF_STATUS_ISOCHRONOUS_XFR
value|(1<< 16)
define|#
directive|define
name|USBPF_STATUS_CURR_DMA_SET
value|(1<< 17)
define|#
directive|define
name|USBPF_STATUS_CAN_CANCEL_IMMED
value|(1<< 18)
define|#
directive|define
name|USBPF_STATUS_DOING_CALLBACK
value|(1<< 19)
name|u_int32_t
name|up_length
decl_stmt|;
comment|/* Total data length (submit/actual) */
name|u_int32_t
name|up_frames
decl_stmt|;
comment|/* USB frame number (submit/actual) */
name|u_int32_t
name|up_error
decl_stmt|;
comment|/* usb_error_t */
name|u_int32_t
name|up_interval
decl_stmt|;
comment|/* for interrupt and isoc */
comment|/* sizeof(struct usbpf_pkthdr) == 128 bytes */
name|u_char
name|up_reserved
index|[
literal|96
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usbpf_version
block|{
name|u_short
name|uv_major
decl_stmt|;
name|u_short
name|uv_minor
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USBPF_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|USBPF_MINOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|USBPF_IFNAMSIZ
value|32
end_define

begin_struct
struct|struct
name|usbpf_ifreq
block|{
comment|/* bus name, e.g. "usbus0" */
name|char
name|ufr_name
index|[
name|USBPF_IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Structure for UIOCSETF.  */
end_comment

begin_struct
struct|struct
name|usbpf_program
block|{
name|u_int
name|uf_len
decl_stmt|;
name|struct
name|usbpf_insn
modifier|*
name|uf_insns
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Struct returned by UIOCGSTATS.  */
end_comment

begin_struct
struct|struct
name|usbpf_stat
block|{
name|u_int
name|us_recv
decl_stmt|;
comment|/* number of packets received */
name|u_int
name|us_drop
decl_stmt|;
comment|/* number of packets dropped */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UIOCGBLEN
value|_IOR('U', 102, u_int)
end_define

begin_define
define|#
directive|define
name|UIOCSBLEN
value|_IOWR('U', 102, u_int)
end_define

begin_define
define|#
directive|define
name|UIOCSETF
value|_IOW('U', 103, struct usbpf_program)
end_define

begin_define
define|#
directive|define
name|UIOCSETIF
value|_IOW('U', 108, struct usbpf_ifreq)
end_define

begin_define
define|#
directive|define
name|UIOCSRTIMEOUT
value|_IOW('U', 109, struct timeval)
end_define

begin_define
define|#
directive|define
name|UIOCGRTIMEOUT
value|_IOR('U', 110, struct timeval)
end_define

begin_define
define|#
directive|define
name|UIOCGSTATS
value|_IOR('U', 111, struct usbpf_stat)
end_define

begin_define
define|#
directive|define
name|UIOCVERSION
value|_IOR('U', 113, struct usbpf_version)
end_define

begin_define
define|#
directive|define
name|UIOCSETWF
value|_IOW('U', 123, struct usbpf_program)
end_define

begin_define
define|#
directive|define
name|USBPF_XFERTAP_SUBMIT
value|0
end_define

begin_define
define|#
directive|define
name|USBPF_XFERTAP_DONE
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|usbpf_attach
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|,
name|struct
name|usbpf_if
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbpf_detach
parameter_list|(
name|struct
name|usb_bus
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usbpf_xfertap
parameter_list|(
name|struct
name|usb_xfer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

