begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  C K U C M D . H  --  Header file for Unix cmd package  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKUCMD_H
end_ifndef

begin_define
define|#
directive|define
name|CKUCMD_H
end_define

begin_comment
comment|/* Special getchars... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_comment
comment|/* Dynamic command buffers */
end_comment

begin_define
define|#
directive|define
name|DCMDBUF
end_define

begin_comment
comment|/*   Use malloc() to allocate the many command-related buffers in ckucmd.c. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|vms_getchar()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|coninc(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aegis */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AMIGA
end_ifdef

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|coninc(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIGA */
end_comment

begin_comment
comment|/* Sizes of things */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CMDDEP
end_ifndef

begin_define
define|#
directive|define
name|CMDDEP
value|20
end_define

begin_comment
comment|/* Maximum command recursion depth */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMDDEP */
end_comment

begin_define
define|#
directive|define
name|HLPLW
value|78
end_define

begin_comment
comment|/* Width of ?-help line */
end_comment

begin_define
define|#
directive|define
name|HLPCW
value|19
end_define

begin_comment
comment|/* Width of ?-help column */
end_comment

begin_define
define|#
directive|define
name|HLPBL
value|100
end_define

begin_comment
comment|/* Help string buffer length */
end_comment

begin_define
define|#
directive|define
name|ATMBL
value|256
end_define

begin_comment
comment|/* Command atom buffer length*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOSPL
end_ifdef

begin_comment
comment|/* No script programming language, save some space */
end_comment

begin_define
define|#
directive|define
name|CMDBL
value|512
end_define

begin_comment
comment|/* Command buffer length */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CMDBL
value|1024
end_define

begin_comment
comment|/* Command buffer length */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSPL */
end_comment

begin_comment
comment|/* Special characters */
end_comment

begin_define
define|#
directive|define
name|RDIS
value|0022
end_define

begin_comment
comment|/* Redisplay   (^R) */
end_comment

begin_define
define|#
directive|define
name|LDEL
value|0025
end_define

begin_comment
comment|/* Delete line (^U) */
end_comment

begin_define
define|#
directive|define
name|WDEL
value|0027
end_define

begin_comment
comment|/* Delete word (^W) */
end_comment

begin_comment
comment|/* Keyword table flags */
end_comment

begin_define
define|#
directive|define
name|CM_INV
value|1
end_define

begin_comment
comment|/* Invisible keyword */
end_comment

begin_define
define|#
directive|define
name|CM_ABR
value|2
end_define

begin_comment
comment|/* Abbreviation */
end_comment

begin_comment
comment|/* Token flags */
end_comment

begin_define
define|#
directive|define
name|CMT_COM
value|0
end_define

begin_comment
comment|/* Comment (; or #) */
end_comment

begin_define
define|#
directive|define
name|CMT_SHE
value|1
end_define

begin_comment
comment|/* Shell escape (!) */
end_comment

begin_define
define|#
directive|define
name|CMT_LBL
value|2
end_define

begin_comment
comment|/* Label (:) */
end_comment

begin_define
define|#
directive|define
name|CMT_FIL
value|3
end_define

begin_comment
comment|/* Indirect filespec (@) */
end_comment

begin_comment
comment|/* Keyword Table Template */
end_comment

begin_struct
struct|struct
name|keytab
block|{
comment|/* Keyword table */
name|char
modifier|*
name|kwd
decl_stmt|;
comment|/* Pointer to keyword string */
name|int
name|kwval
decl_stmt|;
comment|/* Associated value */
name|int
name|flgs
decl_stmt|;
comment|/* Flags (as defined above) */
block|}
struct|;
end_struct

begin_comment
comment|/* Function prototypes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_comment
comment|/* ANSI C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_SYSV
end_ifdef

begin_comment
comment|/* SCO Microsoft C wants no args */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xx_strp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xx_strp
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_SYSV */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI C */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xx_strp
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|int xxesc
argument_list|,
argument|(char **)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID cmsetp
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID cmsavp
argument_list|,
argument|(char [], int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID prompt
argument_list|,
argument|(xx_strp)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID pushcmd
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID cmres
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID cmini
argument_list|,
argument|(int)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmpush
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmpop
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID untab
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmnum
argument_list|,
argument|(char *, char *, int, int *, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmofi
argument_list|,
argument|(char *, char *, char **, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmifi
argument_list|,
argument|(char *, char *, char **, int *, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmdir
argument_list|,
argument|(char *, char *, char **, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmfld
argument_list|,
argument|(char *, char *, char **, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmtxt
argument_list|,
argument|(char *, char *, char **, xx_strp )
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmkey
argument_list|,
argument|(struct keytab [], int, char *, char *, xx_strp)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmkey2
argument_list|,
argument|(struct keytab [], int, char *, char *, char *,xx_strp)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chktok
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmcfm
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int rdigits
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int chknum
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int lower
argument_list|,
argument|(char *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int lookup
argument_list|,
argument|(struct keytab [], char *, int, int *)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int ungword
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DCMDBUF
end_ifdef

begin_macro
name|_PROTOTYP
argument_list|(
argument|int cmsetup
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DCMDBUF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKUCMD_H */
end_comment

begin_comment
comment|/* End of ckucmd.h */
end_comment

end_unit

