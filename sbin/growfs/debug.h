begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Christoph Herrmann, Thomas-Henning von Kamptz  * Copyright (c) 1980, 1989, 1993 The Regents of the University of California.  * All rights reserved.  *   * This code is derived from software contributed to Berkeley by  * Christoph Herrmann and Thomas-Henning von Kamptz, Munich and Frankfurt.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors, as well as Christoph  *      Herrmann and Thomas-Henning von Kamptz.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $TSHeader: src/sbin/growfs/debug.h,v 1.2 2000/11/16 18:43:50 tom Exp $  * $FreeBSD$  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FS_DEBUG
end_ifdef

begin_comment
comment|/* ********************************************************** INCLUDES ***** */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ufs/dinode.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_function_decl
name|void
name|dbg_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_hex
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_fs
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_cg
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_csum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|csum
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_ino
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dinode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_iblk
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_inmap
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_frmap
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_clmap
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_clsum
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dbg_dump_sptbl
parameter_list|(
name|struct
name|fs
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|cg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DBG_OPEN
parameter_list|(
name|P
parameter_list|)
value|dbg_open((P))
end_define

begin_define
define|#
directive|define
name|DBG_CLOSE
value|dbg_close()
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_HEX
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_hex((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_FS
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
value|dbg_dump_fs((F),(C))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CG
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_cg((C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CSUM
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_csum((C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_INO
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_ino((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_IBLK
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|,
name|L
parameter_list|)
value|dbg_dump_iblk((F),(C),(M),(L))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_INMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_inmap((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_FRMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_frmap((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CLMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_clmap((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CLSUM
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_clsum((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_SPTBL
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
value|dbg_dump_sptbl((F),(C),(M))
end_define

begin_define
define|#
directive|define
name|DL_TRC
value|0x01
end_define

begin_define
define|#
directive|define
name|DL_INFO
value|0x02
end_define

begin_decl_stmt
specifier|extern
name|int
name|_dbg_lvl_
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DBG_FUNC
parameter_list|(
name|N
parameter_list|)
value|char __FKT__[] = (N);
end_define

begin_define
define|#
directive|define
name|DBG_ENTER
value|if(_dbg_lvl_& DL_TRC) {                                    \ 	fprintf(stderr, "~>%s: %s\n", __FILE__, __FKT__ );                    \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_LEAVE
value|if(_dbg_lvl_& DL_TRC) {                                    \ 	fprintf(stderr, "~<%s[%d]: %s\n", __FILE__, __LINE__, __FKT__ );      \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_TRC
value|if(_dbg_lvl_& DL_TRC) {                                      \ 	fprintf(stderr, "~=%s[%d]: %s\n", __FILE__, __LINE__, __FKT__ );      \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_PRINT0
parameter_list|(
name|A
parameter_list|)
value|if(_dbg_lvl_& DL_INFO) {                               \ 	fprintf(stderr, "~ %s", (A));                                         \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_PRINT1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|if(_dbg_lvl_& DL_INFO) {                             \ 	fprintf(stderr, "~ ");                                                \ 	fprintf(stderr, (A), (B));                                            \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_PRINT2
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
value|if(_dbg_lvl_& DL_INFO) {                           \ 	fprintf(stderr, "~ ");                                                \ 	fprintf(stderr, (A), (B), (C));                                       \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_PRINT3
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
value|if(_dbg_lvl_& DL_INFO) {                         \ 	fprintf(stderr, "~ ");                                                \ 	fprintf(stderr, (A), (B), (C), (D));                                  \ 	}
end_define

begin_define
define|#
directive|define
name|DBG_PRINT4
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|)
value|if(_dbg_lvl_& DL_INFO) {                       \ 	fprintf(stderr, "~ ");                                                \ 	fprintf(stderr, (A), (B), (C), (D), (E));                             \ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not FS_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DBG_OPEN
parameter_list|(
name|P
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_CLOSE
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_HEX
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_FS
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CG
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CSUM
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_INO
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_IBLK
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|,
name|L
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_INMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_FRMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CLMAP
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_CLSUM
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_DUMP_SPTBL
parameter_list|(
name|F
parameter_list|,
name|C
parameter_list|,
name|M
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_FUNC
parameter_list|(
name|N
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_ENTER
end_define

begin_define
define|#
directive|define
name|DBG_TRC
end_define

begin_define
define|#
directive|define
name|DBG_LEAVE
end_define

begin_define
define|#
directive|define
name|DBG_PRINT0
parameter_list|(
name|A
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_PRINT1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_PRINT2
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_PRINT3
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBG_PRINT4
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FS_DEBUG */
end_comment

end_unit

