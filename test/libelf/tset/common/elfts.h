begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006,2010 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: elfts.h 1337 2010-12-31 15:38:31Z jkoshy $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_TS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ELF_TS_H_
value|1
end_define

begin_comment
comment|/*  * Common definitions used by test cases.  */
end_comment

begin_comment
comment|/* Invocable component requires elf_version() to be set. */
end_comment

begin_define
define|#
directive|define
name|IC_REQUIRES_VERSION_INIT
parameter_list|()
define|\
value|extern int elfts_tcinit;					\ 	void	(*tet_startup)(void) = elfts_init_version
end_define

begin_comment
comment|/* Test purpose needs to check for initialization success */
end_comment

begin_define
define|#
directive|define
name|TP_CHECK_INITIALIZATION
parameter_list|()
value|do {			\ 		if (elfts_tcinit != TET_PASS) {			\ 			tet_infoline("unresolved: test case setup "	\ 			    "failed.");					\ 			tet_result(elfts_tcinit);			\ 			return;						\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Treat a memory area as containing ELF data */
end_comment

begin_define
define|#
directive|define
name|TS_OPEN_MEMORY
parameter_list|(
name|E
parameter_list|,
name|M
parameter_list|)
value|do	{				\ 		if (((E) = elf_memory((M), sizeof((M)))) == NULL) {	\ 			tet_infoline("unresolved: elf_memory() "	\ 			    "failed.");					\ 			tet_result(TET_UNRESOLVED);			\ 			return;						\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Get an ELF descriptor for a file */
end_comment

begin_define
define|#
directive|define
name|_TS_OPEN_FILE
parameter_list|(
name|E
parameter_list|,
name|FN
parameter_list|,
name|CMD
parameter_list|,
name|FD
parameter_list|,
name|ACTION
parameter_list|)
value|do	{		\ 		if (((E) = elfts_open_file((FN),(CMD),&(FD))) == NULL)	\ 			ACTION						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_OPEN_FILE
parameter_list|(
name|E
parameter_list|,
name|FN
parameter_list|,
name|CMD
parameter_list|,
name|FD
parameter_list|)
value|_TS_OPEN_FILE(E,FN,CMD,FD,return;)
end_define

begin_define
define|#
directive|define
name|_TS_WRITE_FILE
parameter_list|(
name|FN
parameter_list|,
name|DATA
parameter_list|,
name|DSZ
parameter_list|,
name|ACTION
parameter_list|)
value|do	{		\ 		int _fd;						\ 		if ((_fd = open((FN), O_CREAT|O_WRONLY, 0666))< 0) {	\ 			tet_printf("unresolved: open("FN") failed: %s.",\ 			    strerror(errno));				\ 			ACTION						\ 		}							\ 		if (write(_fd, (DATA), (DSZ)) != (DSZ)) {		\ 			tet_printf("unresolved: write("FN") failed: %s.",\ 			    strerror(errno));				\ 			ACTION						\ 		}							\ 		(void) close(_fd);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|_TS_READ_FILE
parameter_list|(
name|FN
parameter_list|,
name|DATA
parameter_list|,
name|DSZ
parameter_list|,
name|ACTION
parameter_list|)
value|do	{		\ 		int _fd;						\ 		size_t _rsz, _sz;					\ 		struct stat _sb;					\ 		if ((_fd = open((FN), O_RDONLY, 0))< 0) {		\ 			tet_printf("unresolved: open("FN") failed: %s.", \ 			    strerror(errno));				\ 			ACTION						\ 		}							\ 		if (fstat(_fd,&_sb)< 0) {				\ 			tet_printf("unresolved: fstat("FN") failed: %s.", \ 			    strerror(errno));				\ 			ACTION						\ 		}							\ 		if ((DSZ)< _sb.st_size)				\ 			_sz = (DSZ);					\ 		else							\ 			_sz = _sb.st_size;				\ 		if ((_rsz = read(_fd, (DATA), _sz)) != _sz) {		\ 			tet_printf("unresolved: read("FN") failed: %s.", \ 			    strerror(errno));				\ 			ACTION						\ 		}							\ 		(void) close(_fd);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|TS_NEWFILE
value|"new.file"
end_define

begin_function_decl
name|void
name|elfts_init_version
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Elf
modifier|*
name|elfts_open_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_fn
parameter_list|,
name|Elf_Cmd
name|_cmd
parameter_list|,
name|int
modifier|*
name|_fdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|elfts_compare_files
parameter_list|(
specifier|const
name|char
modifier|*
name|_reffn
parameter_list|,
specifier|const
name|char
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|elfts_copy_file
parameter_list|(
specifier|const
name|char
modifier|*
name|_fn
parameter_list|,
name|int
modifier|*
name|_error
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBELF_TS_H_ */
end_comment

end_unit

