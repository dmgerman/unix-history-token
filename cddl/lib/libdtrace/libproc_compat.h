begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 The FreeBSD Foundation   * All rights reserved.   *   * This software was developed by Rui Paulo under sponsorship from the  * FreeBSD Foundation.   *    * Redistribution and use in source and binary forms, with or without   * modification, are permitted provided that the following conditions   * are met:   * 1. Redistributions of source code must retain the above copyright   *    notice, this list of conditions and the following disclaimer.   * 2. Redistributions in binary form must reproduce the above copyright   *    notice, this list of conditions and the following disclaimer in the   *    documentation and/or other materials provided with the distribution.   *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND   * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE   * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL   * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS   * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)   * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT   * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY   * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF   * SUCH DAMAGE.   *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Compatibility functions between Solaris libproc and FreeBSD libproc.  * Functions sorted alphabetically.  */
end_comment

begin_define
define|#
directive|define
name|PR_LMID_EVERY
value|0
end_define

begin_define
define|#
directive|define
name|Psetrun
parameter_list|(
name|p
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|)
value|proc_continue((p))
end_define

begin_define
define|#
directive|define
name|Pxlookup_by_addr
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|sym
parameter_list|,
name|i
parameter_list|)
define|\
value|proc_addr2sym(p, a, n, s, sym)
end_define

begin_define
define|#
directive|define
name|Pxlookup_by_name
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|,
name|sym
parameter_list|,
name|a
parameter_list|)
define|\
value|proc_name2sym((p), (s1), (s2), (sym))
end_define

begin_define
define|#
directive|define
name|Paddr_to_map
value|proc_addr2map
end_define

begin_define
define|#
directive|define
name|Pcreate_error
value|strerror
end_define

begin_define
define|#
directive|define
name|Pdelbkpt
value|proc_bkptdel
end_define

begin_define
define|#
directive|define
name|Pgrab_error
value|strerror
end_define

begin_define
define|#
directive|define
name|Plmid_to_map
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|,
name|o
parameter_list|)
value|proc_obj2map((p), (o))
end_define

begin_define
define|#
directive|define
name|Plookup_by_addr
value|proc_addr2sym
end_define

begin_define
define|#
directive|define
name|Pname_to_ctf
parameter_list|(
name|p
parameter_list|,
name|obj
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|Pname_to_map
value|proc_name2map
end_define

begin_define
define|#
directive|define
name|Pobject_iter
value|proc_iter_objs
end_define

begin_define
define|#
directive|define
name|Pobject_iter_resolved
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|arg
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|Pobjname
value|proc_objname
end_define

begin_define
define|#
directive|define
name|Pread
value|proc_read
end_define

begin_define
define|#
directive|define
name|Prd_agent
value|proc_rdagent
end_define

begin_define
define|#
directive|define
name|Prelease
value|proc_detach
end_define

begin_define
define|#
directive|define
name|Psetbkpt
value|proc_bkptset
end_define

begin_define
define|#
directive|define
name|Psetflags
value|proc_setflags
end_define

begin_define
define|#
directive|define
name|Pstate
value|proc_state
end_define

begin_define
define|#
directive|define
name|Pstate
value|proc_state
end_define

begin_define
define|#
directive|define
name|Psymbol_iter_by_addr
value|proc_iter_symbyaddr
end_define

begin_define
define|#
directive|define
name|Punsetflags
value|proc_clearflags
end_define

begin_define
define|#
directive|define
name|Pupdate_maps
parameter_list|(
name|p
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|Pupdate_syms
value|proc_updatesyms
end_define

begin_define
define|#
directive|define
name|Pxecbkpt
value|proc_bkptexec
end_define

end_unit

