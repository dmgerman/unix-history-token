begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: gelf_ehdr_template.h 223 2008-08-10 15:40:06Z jkoshy $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_include
include|#
directive|include
file|<libelf.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"tet_api.h"
end_include

begin_comment
comment|/*  * Boilerplate for testing gelf_getehdr() and gelf_newehdr().  *  * Usage:  *  * For gelf_getehdr() define:  *   #define	TC_ICFUNC(E,V)	gelf_getehdr(E,V)  * For gelf_newehdr() define:  #   #define	TC_ICFUNC(E,V)  * #include "gelf_getehdr_template.c"  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|IC_REQUIRES_VERSION_INIT
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The values here must match those in the "ehdr.yaml" file.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_SIGFIELD
parameter_list|(
name|E
parameter_list|,
name|I
parameter_list|,
name|V
parameter_list|)
value|do {					\ 		if ((E)->e_ident[EI_##I] != (V)) {			\ 			tet_printf("fail: " #I " value 0x%x != "	\ 			    "expected 0x%x.", (E)->e_ident[EI_##I],	\ 			    (V));					\ 			result = TET_FAIL;				\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_SIG
parameter_list|(
name|E
parameter_list|,
name|ED
parameter_list|,
name|EC
parameter_list|,
name|EV
parameter_list|,
name|EABI
parameter_list|,
name|EABIVER
parameter_list|)
value|do {		\ 		if ((E)->e_ident[EI_MAG0] != ELFMAG0 ||			\ 		    (E)->e_ident[EI_MAG1] != ELFMAG1 ||			\ 		    (E)->e_ident[EI_MAG2] != ELFMAG2 ||			\ 		    (E)->e_ident[EI_MAG3] != ELFMAG3) {			\ 			tet_printf("fail: incorrect ELF signature "	\ 			    "(%x %x %x %x).", (E)->e_ident[EI_MAG0],	\ 			    (E)->e_ident[EI_MAG1], (E)->e_ident[EI_MAG2],\ 			    (E)->e_ident[EI_MAG3]);			\ 			result = TET_FAIL;				\ 		}							\ 		CHECK_SIGFIELD(E,CLASS,		EC);			\ 		CHECK_SIGFIELD(E,DATA,		ED);			\ 		CHECK_SIGFIELD(E,VERSION,	EV);			\ 		CHECK_SIGFIELD(E,OSABI,		EABI);			\ 		CHECK_SIGFIELD(E,ABIVERSION,	EABIVER);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_FIELD
parameter_list|(
name|E
parameter_list|,
name|FIELD
parameter_list|,
name|VALUE
parameter_list|)
value|do {				\ 		if ((E)->e_##FIELD != (VALUE)) {			\ 			tet_printf("fail: field \"%s\" actual 0x%jx "	\ 			    "!= expected 0x%jx.", #FIELD, 		\ 			    (uintmax_t) (E)->e_##FIELD,			\ 			    (uintmax_t) (VALUE));			\ 			tet_result(TET_FAIL);				\ 			return;						\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CHECK_EHDR
parameter_list|(
name|E
parameter_list|,
name|ED
parameter_list|,
name|EC
parameter_list|)
value|do {					\ 		CHECK_SIG(E,ED,EC,EV_CURRENT,ELFOSABI_FREEBSD,1);	\ 		CHECK_FIELD(E,type,	ET_REL);			\ 		CHECK_FIELD(E,machine,	0x42);				\ 		CHECK_FIELD(E,version,	EV_CURRENT);			\ 		CHECK_FIELD(E,entry,	0xF0F0F0F0);			\ 		CHECK_FIELD(E,phoff,	0x0E0E0E0E);			\ 		CHECK_FIELD(E,shoff,	0xD0D0D0D0);			\ 		CHECK_FIELD(E,flags,	64+8+2+1);			\ 		CHECK_FIELD(E,ehsize,	0x0A0A);			\ 		CHECK_FIELD(E,phentsize,0xB0B0);			\ 		CHECK_FIELD(E,phnum,	0x0C0C);			\ 		CHECK_FIELD(E,shentsize,0xD0D0);			\ 		CHECK_FIELD(E,shnum,	0x0E0E);			\ 		CHECK_FIELD(E,shstrndx,	0xF0F0);			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|COMPARE_SIG
parameter_list|(
name|FN
parameter_list|,
name|H1
parameter_list|,
name|H2
parameter_list|)
value|do {					\ 		if (memcmp(H1.e_ident,H2.e_ident,EI_NIDENT) != 0) {	\ 			tet_printf("fail: \"%s\" e_ident mismatch.",	\ 			    FN);					\ 			result = TET_FAIL;				\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|COMPARE_FIELD
parameter_list|(
name|FN
parameter_list|,
name|H1
parameter_list|,
name|H2
parameter_list|,
name|FIELD
parameter_list|)
value|do {				\ 		if (H1.e_##FIELD != H2.e_##FIELD) {			\ 			tet_printf("fail: \"%s\" (e_" #FIELD ") 0x%jx "	\ 			    "!= 0x%jx.", FN, (uintmax_t) H1.e_##FIELD,	\ 			    (uintmax_t) H2.e_##FIELD);			\ 			result = TET_FAIL;				\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|COMPARE_EHDR
parameter_list|(
name|FN
parameter_list|,
name|H1
parameter_list|,
name|H2
parameter_list|)
value|do {					\ 		COMPARE_SIG(FN,H1,H2);					\ 		COMPARE_FIELD(FN,H1,H2,type);				\ 		COMPARE_FIELD(FN,H1,H2,machine);			\ 		COMPARE_FIELD(FN,H1,H2,version);			\ 		COMPARE_FIELD(FN,H1,H2,entry);				\ 		COMPARE_FIELD(FN,H1,H2,phoff);				\ 		COMPARE_FIELD(FN,H1,H2,shoff);				\ 		COMPARE_FIELD(FN,H1,H2,flags);				\ 		COMPARE_FIELD(FN,H1,H2,ehsize);				\ 		COMPARE_FIELD(FN,H1,H2,phentsize);			\ 		COMPARE_FIELD(FN,H1,H2,phnum);				\ 		COMPARE_FIELD(FN,H1,H2,shentsize);			\ 		COMPARE_FIELD(FN,H1,H2,shnum);				\ 		COMPARE_FIELD(FN,H1,H2,shstrndx);			\ 	} while (0)
end_define

begin_comment
comment|/*  * Non-ELF data.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|data
index|[]
init|=
literal|"This isn't an ELF file."
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A malformed (too short) ELF header.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|badelftemplate
index|[
name|EI_NIDENT
operator|+
literal|1
index|]
init|=
block|{
index|[
name|EI_MAG0
index|]
operator|=
literal|'\177'
block|,
index|[
name|EI_MAG1
index|]
operator|=
literal|'E'
block|,
index|[
name|EI_MAG2
index|]
operator|=
literal|'L'
block|,
index|[
name|EI_MAG3
index|]
operator|=
literal|'F'
block|,
index|[
name|EI_NIDENT
index|]
operator|=
literal|'@'
block|}
decl_stmt|;
end_decl_stmt

end_unit

