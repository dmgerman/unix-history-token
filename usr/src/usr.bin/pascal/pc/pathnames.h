begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pathnames.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|_PATH_PC0
value|"/usr/libexec/pascal/pc0"
end_define

begin_define
define|#
directive|define
name|_PATH_PC1
value|"/usr/libexec/f1"
end_define

begin_define
define|#
directive|define
name|_PATH_PC2
value|"/usr/libexec/pascal/pc2"
end_define

begin_define
define|#
directive|define
name|_PATH_C2
value|"/usr/libexec/c2"
end_define

begin_define
define|#
directive|define
name|_PATH_PC3
value|"/usr/libexec/pascal/pc3"
end_define

begin_define
define|#
directive|define
name|_PATH_PCEXTERN
value|"/usr/lib/pcexterns.o"
end_define

begin_define
define|#
directive|define
name|_PATH_AS
value|"/usr/old/bin/as"
end_define

begin_define
define|#
directive|define
name|_PATH_LD
value|"/usr/old/bin/ld"
end_define

begin_define
define|#
directive|define
name|_PATH_CRT0
value|"/usr/lib/crt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_MCRT0
value|"/usr/lib/mcrt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_GCRT0
value|"/usr/lib/gcrt0.o"
end_define

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp"
end_define

begin_define
define|#
directive|define
name|_PATH_CAT
value|"/bin/cat"
end_define

begin_define
define|#
directive|define
name|_PATH_HOWPC
value|"/usr/libdata/pascal/how_pc"
end_define

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|_PATH_DPC0
value|"/usr/src/pgrm/pascal/pc0/obj/pc0"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DPC1
value|"/usr/src/libexec/pcc/f1.vax/obj/f1"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DPC1
value|"/usr/src/libexec/pcc/f1.tahoe/obj/f1"
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|NO
name|F1
name|PROGRAM
name|AVAILABLE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_DPC2
value|"/usr/src/pgrm/pascal/pc2/obj/pc2"
end_define

begin_define
define|#
directive|define
name|_PATH_DPC3
value|"/usr/src/pgrm/pascal/pc3/obj/pc3"
end_define

begin_define
define|#
directive|define
name|_PATH_DLPC
value|"/usr/src/lib/libpc/obj/libpc.a"
end_define

end_unit

