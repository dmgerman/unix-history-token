begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2003  * 	Hidetoshi Shimokawa. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *  *	This product includes software developed by Hidetoshi Shimokawa.  *  * 4. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $Id: dconschat.c,v 1.76 2003/10/23 06:21:13 simokawa Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<dev/dcons/dcons.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/eui64.h>
end_include

begin_include
include|#
directive|include
file|<sys/event.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<arpa/telnet.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<dev/firewire/firewire.h>
end_include

begin_include
include|#
directive|include
file|<dev/firewire/iec13213.h>
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_define
define|#
directive|define
name|DCONS_POLL_HZ
value|100
end_define

begin_define
define|#
directive|define
name|DCONS_POLL_OFFLINE
value|2
end_define

begin_comment
comment|/* sec */
end_comment

begin_define
define|#
directive|define
name|RETRY
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CSRVAL_VENDOR_PRIVATE
end_ifdef

begin_define
define|#
directive|define
name|USE_CROM
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_CROM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|verbose
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tc_set
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|poll_hz
init|=
name|DCONS_POLL_HZ
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IS_CONSOLE
parameter_list|(
name|p
parameter_list|)
value|((p)->port == 0)
end_define

begin_define
define|#
directive|define
name|IS_GDB
parameter_list|(
name|p
parameter_list|)
value|((p)->port == 1)
end_define

begin_struct
specifier|static
struct|struct
name|dcons_state
block|{
name|int
name|fd
decl_stmt|;
name|kvm_t
modifier|*
name|kd
decl_stmt|;
name|int
name|kq
decl_stmt|;
name|off_t
name|paddr
decl_stmt|;
define|#
directive|define
name|F_READY
value|(1<< 1)
define|#
directive|define
name|F_RD_ONLY
value|(1<< 2)
define|#
directive|define
name|F_ALT_BREAK
value|(1<< 3)
define|#
directive|define
name|F_TELNET
value|(1<< 4)
define|#
directive|define
name|F_USE_CROM
value|(1<< 5)
define|#
directive|define
name|F_ONE_SHOT
value|(1<< 6)
define|#
directive|define
name|F_REPLAY
value|(1<< 7)
name|int
name|flags
decl_stmt|;
enum|enum
block|{
name|TYPE_KVM
block|,
name|TYPE_FW
block|}
name|type
enum|;
name|int
name|escape_state
decl_stmt|;
struct|struct
name|dcons_port
block|{
name|int
name|port
decl_stmt|;
name|struct
name|dcons_ch
name|o
decl_stmt|;
name|struct
name|dcons_ch
name|i
decl_stmt|;
name|u_int32_t
name|optr
decl_stmt|;
name|u_int32_t
name|iptr
decl_stmt|;
name|int
name|s
decl_stmt|;
name|int
name|infd
decl_stmt|;
name|int
name|outfd
decl_stmt|;
name|struct
name|addrinfo
modifier|*
name|res
decl_stmt|;
name|int
name|skip_read
decl_stmt|;
block|}
name|port
index|[
name|DCONS_NPORT
index|]
struct|;
name|struct
name|timespec
name|to
decl_stmt|;
name|struct
name|timespec
name|zero
decl_stmt|;
name|struct
name|termios
name|tsave
decl_stmt|;
block|}
name|sc
struct|;
end_struct

begin_function
specifier|static
name|int
name|dread
parameter_list|(
name|struct
name|dcons_state
modifier|*
name|dc
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
switch|switch
condition|(
name|dc
operator|->
name|type
condition|)
block|{
case|case
name|TYPE_FW
case|:
return|return
operator|(
name|pread
argument_list|(
name|dc
operator|->
name|fd
argument_list|,
name|buf
argument_list|,
name|n
argument_list|,
name|offset
argument_list|)
operator|)
return|;
case|case
name|TYPE_KVM
case|:
return|return
operator|(
name|kvm_read
argument_list|(
name|dc
operator|->
name|kd
argument_list|,
name|offset
argument_list|,
name|buf
argument_list|,
name|n
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dwrite
parameter_list|(
name|struct
name|dcons_state
modifier|*
name|dc
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|,
name|off_t
name|offset
parameter_list|)
block|{
if|if
condition|(
operator|(
name|dc
operator|->
name|flags
operator|&
name|F_RD_ONLY
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|n
operator|)
return|;
switch|switch
condition|(
name|dc
operator|->
name|type
condition|)
block|{
case|case
name|TYPE_FW
case|:
return|return
operator|(
name|pwrite
argument_list|(
name|dc
operator|->
name|fd
argument_list|,
name|buf
argument_list|,
name|n
argument_list|,
name|offset
argument_list|)
operator|)
return|;
case|case
name|TYPE_KVM
case|:
return|return
operator|(
name|kvm_write
argument_list|(
name|dc
operator|->
name|kd
argument_list|,
name|offset
argument_list|,
name|buf
argument_list|,
name|n
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|dconschat_cleanup
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|struct
name|dcons_state
modifier|*
name|dc
decl_stmt|;
name|dc
operator|=
operator|&
name|sc
expr_stmt|;
if|if
condition|(
name|tc_set
operator|!=
literal|0
condition|)
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|dc
operator|->
name|tsave
argument_list|)
expr_stmt|;
if|if
condition|(
name|sig
operator|>
literal|0
condition|)
name|printf
argument_list|(
literal|"\n[dconschat exiting with signal %d ...]\n"
argument_list|,
name|sig
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"\n[dconschat exiting...]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_if
if|#
directive|if
name|USE_CROM
end_if

begin_function
specifier|static
name|int
name|dconschat_get_crom
parameter_list|(
name|struct
name|dcons_state
modifier|*
name|dc
parameter_list|)
block|{
name|off_t
name|addr
decl_stmt|;
name|int
name|i
decl_stmt|,
name|state
init|=
literal|0
decl_stmt|;
name|u_int32_t
name|buf
decl_stmt|,
name|hi
init|=
literal|0
decl_stmt|,
name|lo
init|=
literal|0
decl_stmt|;
name|struct
name|csrreg
modifier|*
name|reg
decl_stmt|;
name|reg
operator|=
operator|(
expr|struct
name|csrreg
operator|*
operator|)
operator|&
name|buf
expr_stmt|;
name|addr
operator|=
literal|0xffff
expr_stmt|;
name|addr
operator|=
operator|(
name|addr
operator|<<
literal|32
operator|)
operator||
literal|0xf0000400
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|20
init|;
name|i
operator|<
literal|0x400
condition|;
name|i
operator|+=
literal|4
control|)
block|{
if|if
condition|(
name|dread
argument_list|(
name|dc
argument_list|,
operator|&
name|buf
argument_list|,
literal|4
argument_list|,
name|addr
operator|+
name|i
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|verbose
condition|)
name|warn
argument_list|(
literal|"crom read faild"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|buf
operator|=
name|ntohl
argument_list|(
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"%d %02x %06x\n"
argument_list|,
name|state
argument_list|,
name|reg
operator|->
name|key
argument_list|,
name|reg
operator|->
name|val
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|state
condition|)
block|{
case|case
literal|0
case|:
if|if
condition|(
name|reg
operator|->
name|key
operator|==
name|CSRKEY_SPEC
operator|&&
name|reg
operator|->
name|val
operator|==
name|CSRVAL_VENDOR_PRIVATE
condition|)
name|state
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|1
case|:
if|if
condition|(
name|reg
operator|->
name|key
operator|==
name|CSRKEY_VER
operator|&&
name|reg
operator|->
name|val
operator|==
name|DCONS_CSR_VAL_VER
condition|)
name|state
operator|=
literal|2
expr_stmt|;
break|break;
case|case
literal|2
case|:
if|if
condition|(
name|reg
operator|->
name|key
operator|==
name|DCONS_CSR_KEY_HI
condition|)
name|hi
operator|=
name|reg
operator|->
name|val
expr_stmt|;
elseif|else
if|if
condition|(
name|reg
operator|->
name|key
operator|==
name|DCONS_CSR_KEY_LO
condition|)
block|{
name|lo
operator|=
name|reg
operator|->
name|val
expr_stmt|;
goto|goto
name|out
goto|;
block|}
break|break;
block|}
block|}
comment|/* not found */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|out
label|:
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"addr: %06x %06x\n"
argument_list|,
name|hi
argument_list|,
name|lo
argument_list|)
expr_stmt|;
name|dc
operator|->
name|paddr
operator|=
operator|(
operator|(
name|off_t
operator|)
name|hi
operator|<<
literal|24
operator|)
operator||
name|lo
expr_stmt|;
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

begin_function
specifier|static
name|void
name|dconschat_ready
parameter_list|(
name|struct
name|dcons_state
modifier|*
name|dc
parameter_list|,
name|int
name|ready
parameter_list|,
name|char
modifier|*
name|reason
parameter_list|)
block|{
specifier|static
name|char
name|oldreason
index|[
literal|64
index|]
init|=
literal|""
decl_stmt|;
name|int
name|old
decl_stmt|;
name|old
operator|=
operator|(
name|dc
operator|->
name|flags
operator|&
name|F_READY
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
if|if
condition|(
name|ready
condition|)
block|{
name|dc
operator|->
name|flags
operator||=
name|F_READY
expr_stmt|;
if|if
condition|(
name|ready
operator|!=
name|old
condition|)
name|printf
argument_list|(
literal|"[dcons connected]\r\n"
argument_list|)
expr_stmt|;
name|oldreason
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|dc
operator|->
name|flags
operator|&=
operator|~
name|F_READY
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|oldreason
argument_list|,
name|reason
argument_list|,
sizeof|sizeof
argument_list|(
name|oldreason
argument_list|)
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"[dcons disconnected (%s)]\r\n"
argument_list|,
name|reason
argument_list|)
expr_stmt|;
name|strlcpy
argument_list|(
name|oldreason
argument_list|,
name|reason
argument_list|,
sizeof|sizeof
argument_list|(
name|oldreason
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|dconschat_fetch_header
parameter_list|(
name|struct
name|dcons_state
modifier|*
name|dc
parameter_list|)
block|{
name|char
name|ebuf
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|dcons_buf
name|dbuf
decl_stmt|;
name|int
name|j
decl_stmt|;
if|#
directive|if
name|USE_CROM
if|if
condition|(
name|dc
operator|->
name|paddr
operator|==
literal|0
operator|&&
operator|(
name|dc
operator|->
name|flags
operator|&
name|F_USE_CROM
operator|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|dconschat_get_crom
argument_list|(
name|dc
argument_list|)
condition|)
block|{
name|dconschat_ready
argument_list|(
name|dc
argument_list|,
literal|0
argument_list|,
literal|"get crom failed"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
name|dread
argument_list|(
name|dc
argument_list|,
operator|&
name|dbuf
argument_list|,
name|DCONS_HEADER_SIZE
argument_list|,
name|dc
operator|->
name|paddr
argument_list|)
operator|<
literal|0
condition|)
block|{
name|dconschat_ready
argument_list|(
name|dc
argument_list|,
literal|0
argument_list|,
literal|"read header failed"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|dbuf
operator|.
name|magic
operator|!=
name|htonl
argument_list|(
name|DCONS_MAGIC
argument_list|)
condition|)
block|{
if|if
condition|(
operator|(
name|dc
operator|->
name|flags
operator|&
name|F_USE_CROM
operator|)
operator|!=
literal|0
condition|)
name|dc
operator|->
name|paddr
operator|=
literal|0
expr_stmt|;
name|snprintf
argument_list|(
name|ebuf
argument_list|,
sizeof|sizeof
argument_list|(
name|ebuf
argument_list|)
argument_list|,
literal|"wrong magic 0x%08x"
argument_list|,
name|dbuf
operator|.
name|magic
argument_list|)
expr_stmt|;
name|dconschat_ready
argument_list|(
name|dc
argument_list|,
literal|0
argument_list|,
name|ebuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|ntohl
argument_list|(
name|dbuf
operator|.
name|version
argument_list|)
operator|!=
name|DCONS_VERSION
condition|)
block|{
name|snprintf
argument_list|(
name|ebuf
argument_list|,
sizeof|sizeof
argument_list|(
name|ebuf
argument_list|)
argument_list|,
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
literal|"wrong version %ld,%d"
argument_list|,
else|#
directive|else
literal|"wrong version %d,%d"
argument_list|,
endif|#
directive|endif
name|ntohl
argument_list|(
name|dbuf
operator|.
name|version
argument_list|)
argument_list|,
name|DCONS_VERSION
argument_list|)
expr_stmt|;
comment|/* XXX exit? */
name|dconschat_ready
argument_list|(
name|dc
argument_list|,
literal|0
argument_list|,
name|ebuf
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|DCONS_NPORT
condition|;
name|j
operator|++
control|)
block|{
name|struct
name|dcons_ch
modifier|*
name|o
decl_stmt|,
modifier|*
name|i
decl_stmt|;
name|off_t
name|newbuf
decl_stmt|;
name|int
name|new
init|=
literal|0
decl_stmt|;
name|o
operator|=
operator|&
name|dc
operator|->
name|port
index|[
name|j
index|]
operator|.
name|o
expr_stmt|;
name|newbuf
operator|=
name|dc
operator|->
name|paddr
operator|+
name|ntohl
argument_list|(
name|dbuf
operator|.
name|ooffset
index|[
name|j
index|]
argument_list|)
expr_stmt|;
name|o
operator|->
name|size
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|osize
index|[
name|j
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|newbuf
operator|!=
name|o
operator|->
name|buf
condition|)
block|{
comment|/* buffer address has changes */
name|new
operator|=
literal|1
expr_stmt|;
name|o
operator|->
name|gen
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|optr
index|[
name|j
index|]
argument_list|)
operator|>>
name|DCONS_GEN_SHIFT
expr_stmt|;
name|o
operator|->
name|pos
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|optr
index|[
name|j
index|]
argument_list|)
operator|&
name|DCONS_POS_MASK
expr_stmt|;
name|o
operator|->
name|buf
operator|=
name|newbuf
expr_stmt|;
block|}
name|i
operator|=
operator|&
name|dc
operator|->
name|port
index|[
name|j
index|]
operator|.
name|i
expr_stmt|;
name|i
operator|->
name|size
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|isize
index|[
name|j
index|]
argument_list|)
expr_stmt|;
name|i
operator|->
name|gen
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|iptr
index|[
name|j
index|]
argument_list|)
operator|>>
name|DCONS_GEN_SHIFT
expr_stmt|;
name|i
operator|->
name|pos
operator|=
name|ntohl
argument_list|(
name|dbuf
operator|.
name|iptr
index|[
name|j
index|]
argument_list|)
operator|&
name|DCONS_POS_MASK
expr_stmt|;
name|i
operator|->
name|buf
operator|=
name|dc
operator|->
name|paddr
operator|+
name|ntohl
argument_list|(
name|dbuf
operator|.
name|ioffset
index|[
name|j
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
block|{
name|printf
argument_list|(
literal|"port %d   size offset   gen   pos\n"
argument_list|,
name|j
argument_list|)
expr_stmt|;
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
name|printf
argument_list|(
literal|"output: %5d %6ld %5d %5d\n"
literal|"input : %5d %6ld %5d %5d\n"
argument_list|,
else|#
directive|else
argument|printf(
literal|"output: %5d %6d %5d %5d\n"
literal|"input : %5d %6d %5d %5d\n"
argument|,
endif|#
directive|endif
argument|o->size, ntohl(dbuf.ooffset[j]), o->gen, o->pos, 			i->size, ntohl(dbuf.ioffset[j]), i->gen, i->pos); 		}  		if (IS_CONSOLE(&dc->port[j])&& new&& 		    (dc->flags& F_REPLAY) !=
literal|0
argument|) { 			if (o->gen>
literal|0
argument|) 				o->gen --; 			else 				o->pos =
literal|0
argument|; 		} 	} 	dconschat_ready(dc,
literal|1
argument|, NULL); 	return(
literal|0
argument|); }  static int dconschat_get_ptr (struct dcons_state *dc) { 	int dlen
argument_list|,
argument|i; 	u_int32_t ptr[DCONS_NPORT*
literal|2
argument|+
literal|1
argument|]; 	static int retry = RETRY; 	char ebuf[
literal|64
argument|];  again: 	dlen = dread(dc,&ptr, sizeof(ptr), 		dc->paddr + __offsetof(struct dcons_buf, magic));  	if (dlen<
literal|0
argument|) { 		if (errno == ETIMEDOUT) 			if (retry -->
literal|0
argument|) 				goto again; 		dconschat_ready(dc,
literal|0
argument|,
literal|"get ptr failed"
argument|); 		return(-
literal|1
argument|); 	} 	if (ptr[
literal|0
argument|] != htonl(DCONS_MAGIC)) { 		if ((dc->flags& F_USE_CROM) !=
literal|0
argument|) 			dc->paddr =
literal|0
argument|; 		snprintf(ebuf, sizeof(ebuf),
literal|"wrong magic 0x%08x"
argument|, ptr[
literal|0
argument|]); 		dconschat_ready(dc,
literal|0
argument|, ebuf); 		return(-
literal|1
argument|); 	} 	retry = RETRY; 	for (i =
literal|0
argument|; i< DCONS_NPORT; i ++) { 		dc->port[i].optr = ntohl(ptr[i +
literal|1
argument|]); 		dc->port[i].iptr = ntohl(ptr[DCONS_NPORT + i +
literal|1
argument|]); 	} 	return(
literal|0
argument|); }
define|#
directive|define
name|MAX_XFER
value|2048
argument|static int dconschat_read_dcons(struct dcons_state *dc, int port, char *buf, int len) { 	struct dcons_ch *ch; 	u_int32_t ptr
argument_list|,
argument|pos
argument_list|,
argument|gen
argument_list|,
argument|next_gen; 	int rlen
argument_list|,
argument|dlen
argument_list|,
argument|lost; 	int retry = RETRY;  	ch =&dc->port[port].o; 	ptr = dc->port[port].optr; 	gen = ptr>> DCONS_GEN_SHIFT; 	pos = ptr& DCONS_POS_MASK; 	if (gen == ch->gen&& pos == ch->pos) 		return (-
literal|1
argument|);  	next_gen = DCONS_NEXT_GEN(ch->gen);
comment|/* XXX sanity check */
argument|if (gen == ch->gen) { 		if (pos> ch->pos) 			goto ok; 		lost = ch->size * DCONS_GEN_MASK - ch->pos; 		ch->pos =
literal|0
argument|; 	} else if (gen == next_gen) { 		if (pos<= ch->pos) 			goto ok; 		lost = pos - ch->pos; 		ch->pos = pos; 	} else { 		lost = gen - ch->gen; 		if (lost<
literal|0
argument|) 			lost += DCONS_GEN_MASK; 		if (verbose) 			printf(
literal|"[genskip %d]"
argument|, lost); 		lost = lost * ch->size - ch->pos; 		ch->pos =
literal|0
argument|; 		ch->gen = gen; 	}
comment|/* generation skipped !! */
comment|/* XXX discard */
argument|if (verbose) 		printf(
literal|"[lost %d]"
argument|, lost); ok: 	if (gen == ch->gen) 		rlen = pos - ch->pos; 	else 		rlen = ch->size - ch->pos;  	if (rlen> MAX_XFER) 		rlen = MAX_XFER; 	if (rlen> len) 		rlen = len;
if|#
directive|if
literal|1
argument|if (verbose) 		printf(
literal|"[%d]"
argument|, rlen); fflush(stdout);
endif|#
directive|endif
argument|again: 	dlen = dread(dc, buf, rlen, ch->buf + ch->pos); 	if (dlen<
literal|0
argument|) { 		if (errno == ETIMEDOUT) 			if (retry -->
literal|0
argument|) 				goto again; 		dconschat_ready(dc,
literal|0
argument|,
literal|"read buffer failed"
argument|); 		return(-
literal|1
argument|); 	} 	if (dlen != rlen) 		warnx(
literal|"dlen(%d) != rlen(%d)\n"
argument|, dlen, rlen); 	ch->pos += dlen; 	if (ch->pos>= ch->size) { 		ch->gen = next_gen; 		ch->pos =
literal|0
argument|; 		if (verbose) 			printf(
literal|"read_dcons: gen=%d"
argument|, ch->gen); 	} 	return (dlen); }  static int dconschat_write_dcons(struct dcons_state *dc, int port, char *buf, int blen) { 	struct dcons_ch *ch; 	u_int32_t ptr; 	int len
argument_list|,
argument|wlen; 	int retry = RETRY;  	ch =&dc->port[port].i; 	ptr = dc->port[port].iptr;
comment|/* the others may advance the pointer sync with it */
argument|ch->gen = ptr>> DCONS_GEN_SHIFT; 	ch->pos = ptr& DCONS_POS_MASK;  	while(blen>
literal|0
argument|) { 		wlen = MIN(blen, ch->size - ch->pos); 		wlen = MIN(wlen, MAX_XFER); 		len = dwrite(dc, buf, wlen, ch->buf + ch->pos); 		if (len<
literal|0
argument|) { 			if (errno == ETIMEDOUT) 				if (retry -->
literal|0
argument|) 					continue;
comment|/* try again */
argument|dconschat_ready(dc,
literal|0
argument|,
literal|"write buffer failed"
argument|); 			return(-
literal|1
argument|); 		} 		ch->pos += len; 		buf += len; 		blen -= len; 		if (ch->pos>= ch->size) { 			ch->gen = DCONS_NEXT_GEN(ch->gen); 			ch->pos =
literal|0
argument|; 			if (verbose) 				printf(
literal|"write_dcons: gen=%d"
argument|, ch->gen); 				 		} 	}  	ptr = DCONS_MAKE_PTR(ch); 	dc->port[port].iptr = ptr;  	if (verbose>
literal|2
argument|) 		printf(
literal|"(iptr: 0x%x)"
argument|, ptr); again: 	len = dwrite(dc,&ptr, sizeof(u_int32_t), 		dc->paddr + __offsetof(struct dcons_buf, iptr[port])); 	if (len<
literal|0
argument|) { 		if (errno == ETIMEDOUT) 			if (retry -->
literal|0
argument|) 				goto again; 		dconschat_ready(dc,
literal|0
argument|,
literal|"write ptr failed"
argument|); 		return(-
literal|1
argument|); 	} 	return(
literal|0
argument|); }  static int dconschat_write_socket(int fd, char *buf, int len) { 	write(fd, buf, len); 	if (verbose>
literal|1
argument|) { 		buf[len] =
literal|0
argument|; 		printf(
literal|"[%s]"
argument|, buf); 	} 	return (
literal|0
argument|); }  static void dconschat_init_socket(struct dcons_state *dc, int port, char *host, int sport) { 	struct addrinfo hints
argument_list|,
argument|*res; 	int on =
literal|1
argument_list|,
argument|error; 	char service[
literal|10
argument|]; 	struct kevent kev; 	struct dcons_port *p;  	p =&dc->port[port]; 	p->port = port; 	p->infd = p->outfd = -
literal|1
argument|;  	if (sport<
literal|0
argument|) 		return;  	if (sport ==
literal|0
argument|) {
comment|/* Use stdin and stdout */
argument|p->infd = STDIN_FILENO; 		p->outfd = STDOUT_FILENO; 		p->s = -
literal|1
argument|; 		if (tc_set ==
literal|0
argument|&& 		    tcgetattr(STDIN_FILENO,&dc->tsave) ==
literal|0
argument|) { 			struct termios traw;  			traw = dc->tsave; 			cfmakeraw(&traw); 			tcsetattr(STDIN_FILENO, TCSADRAIN,&traw); 			tc_set =
literal|1
argument|; 		} 		EV_SET(&kev, p->infd, EVFILT_READ, EV_ADD, NOTE_LOWAT,
literal|1
argument|, 		    (void *)p); 		kevent(dc->kq,&kev,
literal|1
argument|, NULL,
literal|0
argument|,&dc->zero); 		return; 	}  	memset(&hints,
literal|0
argument|, sizeof(hints)); 	hints.ai_flags = AI_PASSIVE;
if|#
directive|if
literal|1
comment|/* gdb can talk v4 only */
argument|hints.ai_family = PF_INET;
else|#
directive|else
argument|hints.ai_family = PF_UNSPEC;
endif|#
directive|endif
argument|hints.ai_socktype = SOCK_STREAM; 	hints.ai_protocol =
literal|0
argument|;  	if (verbose) 		printf(
literal|"%s:%d for port %d\n"
argument|, 			host == NULL ?
literal|"*"
argument|: host, sport, port); 	snprintf(service, sizeof(service),
literal|"%d"
argument|, sport); 	error = getaddrinfo(host, service,&hints,&res); 	if (error) 		errx(
literal|1
argument|,
literal|"tcp/%s: %s\n"
argument|, service, gai_strerror(error)); 	p->res = res; 	p->s = socket(res->ai_family, res->ai_socktype, res->ai_protocol); 	if (p->s<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"socket"
argument|); 	setsockopt(p->s, SOL_SOCKET, SO_REUSEADDR,&on, sizeof(on));  	if (bind(p->s, p->res->ai_addr, p->res->ai_addrlen)<
literal|0
argument|) { 		err(
literal|1
argument|,
literal|"bind"
argument|); 	} 	if (listen(p->s,
literal|1
argument|)<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"listen"
argument|); 	EV_SET(&kev, p->s, EVFILT_READ, EV_ADD | EV_ONESHOT,
literal|0
argument|,
literal|0
argument|, (void *)p); 	error = kevent(dc->kq,&kev,
literal|1
argument|, NULL,
literal|0
argument|,&dc->to); 	if (error<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"kevent"
argument|); 	return; }  static int dconschat_accept_socket(struct dcons_state *dc, struct dcons_port *p) { 	socklen_t addrlen; 	int ns
argument_list|,
argument|flags; 	struct kevent kev;
comment|/* accept connection */
argument|addrlen = p->res->ai_addrlen; 	ns = accept(p->s, p->res->ai_addr,&addrlen); 	if (ns<
literal|0
argument|) 		err(
literal|1
argument|,
literal|"accept"
argument|); 	if (verbose) 		printf(
literal|"port%d accepted\n"
argument|, p->port);  	flags = fcntl(ns, F_GETFL,
literal|0
argument|); 	flags |= O_NDELAY; 	fcntl(ns, F_SETFL, flags);
if|#
directive|if
literal|1
argument|if (IS_CONSOLE(p)&& (dc->flags& F_TELNET) !=
literal|0
argument|) { 		char sga[] = {IAC
argument_list|,
argument|WILL
argument_list|,
argument|TELOPT_SGA}; 		char linemode[] = {IAC
argument_list|,
argument|DONT
argument_list|,
argument|TELOPT_LINEMODE}; 		char echo[] = {IAC
argument_list|,
argument|WILL
argument_list|,
argument|TELOPT_ECHO}; 		char bin[] = {IAC
argument_list|,
argument|DO
argument_list|,
argument|TELOPT_BINARY};  		write(ns, sga, sizeof(sga)); 		write(ns, linemode, sizeof(linemode)); 		write(ns, echo, sizeof(echo)); 		write(ns, bin, sizeof(bin)); 		p->skip_read =
literal|0
argument|; 	}
endif|#
directive|endif
argument|p->infd = p->outfd = ns; 	EV_SET(&kev, ns, EVFILT_READ, EV_ADD, NOTE_LOWAT,
literal|1
argument|, (void *)p); 	kevent(dc->kq,&kev,
literal|1
argument|, NULL,
literal|0
argument|,&dc->zero); 	return(
literal|0
argument|); }  static int dconschat_read_filter(struct dcons_state *dc, struct dcons_port *p,     u_char *sp, int slen, u_char *dp, int *dlen) { 	static u_char abreak[
literal|3
argument|] = {
literal|13
comment|/* CR */
argument_list|,
literal|126
comment|/* ~ */
argument_list|,
literal|2
comment|/* ^B */
argument|};  	while (slen>
literal|0
argument|) { 		if (IS_CONSOLE(p)) { 			if ((dc->flags& F_TELNET) !=
literal|0
argument|) {
comment|/* XXX Telnet workarounds */
argument|if (p->skip_read -->
literal|0
argument|) { 					sp ++; 					slen --; 					continue; 				} 				if (*sp == IAC) { 					if (verbose) 						printf(
literal|"(IAC)"
argument|); 					p->skip_read =
literal|2
argument|; 					sp ++; 					slen --; 					continue; 				} 				if (*sp ==
literal|0
argument|) { 					if (verbose) 						printf(
literal|"(0 stripped)"
argument|); 					sp ++; 					slen --; 					continue; 				} 			} 			switch (dc->escape_state) { 			case STATE1: 				if (*sp == KEY_TILDE) 					dc->escape_state = STATE2; 				else 					dc->escape_state = STATE0; 				break; 			case STATE2: 				dc->escape_state = STATE0; 				if (*sp ==
literal|'.'
argument|) 					dconschat_cleanup(
literal|0
argument|); 			} 			if (*sp == KEY_CR) 				dc->escape_state = STATE1; 		} else if (IS_GDB(p)) {
comment|/* GDB: ^C -> CR+~+^B */
argument|if (*sp ==
literal|0x3
argument|&& (dc->flags& F_ALT_BREAK) !=
literal|0
argument|) { 				bcopy(abreak, dp,
literal|3
argument|); 				dp +=
literal|3
argument|; 				sp ++; 				*dlen +=
literal|3
argument|;
comment|/* discard rest of the packet */
argument|slen =
literal|0
argument|; 				break; 			} 		} 		*dp++ = *sp++; 		(*dlen) ++; 		slen --; 	} 	return (*dlen); 			 }  static int dconschat_read_socket(struct dcons_state *dc, struct dcons_port *p) { 	struct kevent kev; 	int len
argument_list|,
argument|wlen; 	char rbuf[MAX_XFER]
argument_list|,
argument|wbuf[MAX_XFER+
literal|2
argument|];  	if ((len = read(p->infd, rbuf, sizeof(rbuf)))>
literal|0
argument|) { 		wlen =
literal|0
argument|; 		dconschat_read_filter(dc, p, rbuf, len, wbuf,&wlen);
comment|/* XXX discard if not ready*/
argument|if (wlen>
literal|0
argument|&& (dc->flags& F_READY) !=
literal|0
argument|) { 			dconschat_write_dcons(dc, p->port, wbuf, wlen); 			if (verbose>
literal|1
argument|) { 				wbuf[wlen] =
literal|0
argument|; 				printf(
literal|"(%s)\n"
argument|, wbuf); 			} 			if (verbose) { 				printf(
literal|"(%d)"
argument|, wlen); 				fflush(stdout); 			} 		} 	} else { 		if (verbose) { 			if (len ==
literal|0
argument|) 				warnx(
literal|"port%d: closed"
argument|, p->port); 			else 				warn(
literal|"port%d: read"
argument|, p->port); 		} 		EV_SET(&kev, p->infd, EVFILT_READ, 			EV_DELETE,
literal|0
argument|,
literal|0
argument|, NULL); 		kevent(dc->kq,&kev,
literal|1
argument|, NULL,
literal|0
argument|,&dc->zero); 		close(p->infd); 		close(p->outfd);
comment|/* XXX exit for pipe case XXX */
argument|EV_SET(&kev, p->s, EVFILT_READ, 				EV_ADD | EV_ONESHOT,
literal|0
argument|,
literal|0
argument|, (void *) p); 		kevent(dc->kq,&kev,
literal|1
argument|, NULL,
literal|0
argument|,&dc->zero); 		p->infd = p->outfd = -
literal|1
argument|; 	} 	return(
literal|0
argument|); }
define|#
directive|define
name|NEVENT
value|5
argument|static int dconschat_proc_socket(struct dcons_state *dc) { 	struct kevent elist[NEVENT]
argument_list|,
argument|*e; 	int i
argument_list|,
argument|n; 	struct dcons_port *p;  	n = kevent(dc->kq, NULL,
literal|0
argument|, elist, NEVENT,&dc->to); 	for (i =
literal|0
argument|; i< n; i ++) { 		e =&elist[i]; 		p = (struct dcons_port *)e->udata; 		if (e->ident == p->s) { 			dconschat_accept_socket(dc, p); 		} else { 			dconschat_read_socket(dc, p); 		} 	} 	return(
literal|0
argument|); }  static int dconschat_proc_dcons(struct dcons_state *dc) { 	int port
argument_list|,
argument|len
argument_list|,
argument|err; 	char buf[MAX_XFER]; 	struct dcons_port *p;  	err = dconschat_get_ptr(dc); 	if (err) {
comment|/* XXX we should stop write operation too. */
argument|return err; 	} 	for (port =
literal|0
argument|; port< DCONS_NPORT; port ++) { 		p =&dc->port[port]; 		if (p->infd<
literal|0
argument|) 			continue; 		while ((len = dconschat_read_dcons(dc, port, buf, 		    sizeof(buf)))>
literal|0
argument|) { 			dconschat_write_socket(p->outfd, buf, len); 			dconschat_get_ptr(dc); 		} 		if ((dc->flags& F_ONE_SHOT) !=
literal|0
argument|&& len<=
literal|0
argument|) 			dconschat_cleanup(
literal|0
argument|); 	} 	return
literal|0
argument|; }  static int dconschat_start_session(struct dcons_state *dc) { 	int counter =
literal|0
argument|;  	while (
literal|1
argument|) { 		if ((dc->flags& F_READY) ==
literal|0
argument|&& 			(++counter % (poll_hz * DCONS_POLL_OFFLINE)) ==
literal|0
argument|) 			dconschat_fetch_header(dc); 		if ((dc->flags& F_READY) !=
literal|0
argument|) 			dconschat_proc_dcons(dc); 		dconschat_proc_socket(dc); 	} 	return (
literal|0
argument|); }  static void usage(void) { 	fprintf(stderr,
literal|"usage: dconschat [-brvwRT1] [-h hz] [-C port] [-G port]\n"
literal|"\t\t\t[-M core] [-N system]\n"
literal|"\t\t\t[-u unit] [-a address] [-t target_eui64]\n"
literal|"\t-b	translate ctrl-C to CR+~+ctrl-B on gdb port\n"
literal|"\t-v	verbose\n"
literal|"\t-w	listen on wildcard address rather than localhost\n"
literal|"\t-r	replay old buffer on connection\n"
literal|"\t-R	read-only\n"
literal|"\t-T	enable Telnet protocol workaround on console port\n"
literal|"\t-1	one shot: read buffer and exit\n"
literal|"\t-h	polling rate\n"
literal|"\t-C	port number for console port\n"
literal|"\t-G	port number for gdb port\n"
literal|"\t(for KVM)\n"
literal|"\t-M	core file\n"
literal|"\t-N	system file\n"
literal|"\t(for FireWire)\n"
literal|"\t-u	specify unit number of the bus\n"
literal|"\t-t	EUI64 of target host (must be specified)\n"
literal|"\t-a	physical address of dcons buffer on target host\n"
argument|); 	exit(
literal|0
argument|); } int main(int argc, char **argv) { 	struct dcons_state *dc; 	struct fw_eui64 eui; 	struct eui64 target; 	char devname[
literal|256
argument|]
argument_list|,
argument|*core = NULL
argument_list|,
argument|*system = NULL; 	int i
argument_list|,
argument|ch
argument_list|,
argument|error; 	int unit=
literal|0
argument_list|,
argument|wildcard=
literal|0
argument|; 	int port[DCONS_NPORT];  	bzero(&sc, sizeof(sc)); 	dc =&sc; 	dc->flags |= USE_CROM ? F_USE_CROM :
literal|0
argument|;
comment|/* default ports */
argument|port[
literal|0
argument|] =
literal|0
argument|;
comment|/* stdin/out for console */
argument|port[
literal|1
argument|] = -
literal|1
argument|;
comment|/* disable gdb port */
argument|while ((ch = getopt(argc, argv,
literal|"a:bh:rt:u:vwC:G:M:N:RT1"
argument|)) != -
literal|1
argument|) { 		switch(ch) { 		case
literal|'a'
argument|: 			dc->paddr = strtoull(optarg, NULL,
literal|0
argument|); 			dc->flags&= ~F_USE_CROM; 			break; 		case
literal|'b'
argument|: 			dc->flags |= F_ALT_BREAK; 			break; 		case
literal|'h'
argument|: 			poll_hz = strtoul(optarg, NULL,
literal|0
argument|); 			if (poll_hz ==
literal|0
argument|) 				poll_hz = DCONS_POLL_HZ; 			break; 		case
literal|'r'
argument|: 			dc->flags |= F_REPLAY; 			break; 		case
literal|'t'
argument|: 			if (eui64_hostton(optarg,&target) !=
literal|0
argument|&& 			    eui64_aton(optarg,&target) !=
literal|0
argument|) 				errx(
literal|1
argument|,
literal|"invalid target: %s"
argument|, optarg); 			eui.hi = ntohl(*(u_int32_t*)&(target.octet[
literal|0
argument|])); 			eui.lo = ntohl(*(u_int32_t*)&(target.octet[
literal|4
argument|])); 			dc->type = TYPE_FW; 			break; 		case
literal|'u'
argument|: 			unit = strtol(optarg, NULL,
literal|0
argument|); 			break; 		case
literal|'v'
argument|: 			verbose ++; 			break; 		case
literal|'w'
argument|: 			wildcard =
literal|1
argument|; 			break; 		case
literal|'C'
argument|: 			port[
literal|0
argument|] = strtol(optarg, NULL,
literal|0
argument|); 			break; 		case
literal|'G'
argument|: 			port[
literal|1
argument|] = strtol(optarg, NULL,
literal|0
argument|); 			break; 		case
literal|'M'
argument|: 			core = optarg; 			break;	 		case
literal|'N'
argument|: 			system = optarg; 			break;	 		case
literal|'R'
argument|: 			dc->flags |= F_RD_ONLY; 			break; 		case
literal|'T'
argument|: 			dc->flags |= F_TELNET; 			break; 		case
literal|'1'
argument|: 			dc->flags |= F_ONE_SHOT | F_REPLAY; 			break; 		default: 			usage(); 		} 	} 	if (dc->paddr ==
literal|0
argument|&& (dc->flags& F_USE_CROM) ==
literal|0
argument|) { 		warnx(
literal|"no address specified"
argument|); 		usage(); 	}  	if (port[
literal|0
argument|]<
literal|0
argument|&& port[
literal|1
argument|]<
literal|0
argument|) { 		warnx(
literal|"no port specified"
argument|); 		usage(); 	}
comment|/* set signal handler */
argument|signal(SIGHUP, dconschat_cleanup); 	signal(SIGINT, dconschat_cleanup); 	signal(SIGPIPE, dconschat_cleanup); 	signal(SIGTERM, dconschat_cleanup);
comment|/* init firewire */
argument|switch (dc->type) { 	case TYPE_FW:
define|#
directive|define
name|MAXDEV
value|10
argument|for (i =
literal|0
argument|; i< MAXDEV; i ++) { 			snprintf(devname, sizeof(devname),
literal|"/dev/fwmem%d.%d"
argument|, unit, i); 			dc->fd = open(devname, O_RDWR); 			if (dc->fd>=
literal|0
argument|) 				goto found; 		} 		err(
literal|1
argument|,
literal|"open"
argument|); found: 		error = ioctl(dc->fd, FW_SDEUI64,&eui); 		if (error) 			err(
literal|1
argument|,
literal|"ioctl"
argument|); 		break; 	case TYPE_KVM: 	{ 		struct nlist nl[] = {{
literal|"dcons_buf"
argument|}
argument_list|,
argument|{
literal|""
argument|}}; 		void *dcons_buf;  		dc->kd = kvm_open(system, core, NULL, 		    (dc->flags& F_RD_ONLY) ? O_RDONLY : O_RDWR,
literal|"dconschat"
argument|); 		if (dc->kd == NULL) 			errx(
literal|1
argument|,
literal|"kvm_open"
argument|);  		if (kvm_nlist(dc->kd, nl)<
literal|0
argument|) 			errx(
literal|1
argument|,
literal|"kvm_nlist: %s"
argument|, kvm_geterr(dc->kd));  		if (kvm_read(dc->kd, nl[
literal|0
argument|].n_value,&dcons_buf, 		    sizeof(void *))<
literal|0
argument|) 			errx(
literal|1
argument|,
literal|"kvm_read: %s"
argument|, kvm_geterr(dc->kd)); 		dc->paddr = (uintptr_t)dcons_buf; 		if (verbose) 			printf(
literal|"dcons_buf: 0x%x\n"
argument|, (uint)dc->paddr); 		break; 	} 	} 	dconschat_fetch_header(dc);
comment|/* init sockets */
argument|dc->kq = kqueue(); 	if (poll_hz ==
literal|1
argument|) { 		dc->to.tv_sec =
literal|1
argument|; 		dc->to.tv_nsec =
literal|0
argument|; 	} else { 		dc->to.tv_sec =
literal|0
argument|; 		dc->to.tv_nsec =
literal|1000
argument|*
literal|1000
argument|*
literal|1000
argument|/ poll_hz; 	} 	dc->zero.tv_sec =
literal|0
argument|; 	dc->zero.tv_nsec =
literal|0
argument|; 	for (i =
literal|0
argument|; i< DCONS_NPORT; i++) 		dconschat_init_socket(dc, i, 		    wildcard ? NULL :
literal|"localhost"
argument|, port[i]);  	dconschat_start_session(dc);  	for (i =
literal|0
argument|; i< DCONS_NPORT; i++) { 		freeaddrinfo(dc->port[i].res); 	} 	return (
literal|0
argument|); }
end_function

end_unit

