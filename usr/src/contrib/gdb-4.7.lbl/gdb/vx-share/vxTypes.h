begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vxTypes.h - VxWorks type definition header */
end_comment

begin_comment
comment|/*  Copyright 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01c,05oct90,shl  added copyright notice.                  made #endif ANSI style. 01b,10aug90,dnw  added VOIDFUNCPTR 01a,29may90,del  written. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCvxTypesh
end_ifndef

begin_define
define|#
directive|define
name|INCvxTypesh
end_define

begin_comment
comment|/* The following stuff must NOT be included if this include file is used  * from assembly language.  Just #define ASMLANGUAGE before the include,  * to get rid of it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASMLANGUAGE
end_ifndef

begin_comment
comment|/* vxWorks types */
end_comment

begin_typedef
typedef|typedef
name|char
name|INT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UCHAR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|USHORT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ULONG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|VOID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ARGINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|FUNCPTR
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* ptr to function returning int */
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
modifier|*
name|VOIDFUNCPTR
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* ptr to function returning VOID */
end_comment

begin_comment
comment|/* historical definitions - now obsolete */
end_comment

begin_typedef
typedef|typedef
name|char
name|TINY
typedef|;
end_typedef

begin_comment
comment|/* obsolete */
end_comment

begin_typedef
typedef|typedef
name|char
name|TBOOL
typedef|;
end_typedef

begin_comment
comment|/* obsolete */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UTINY
typedef|;
end_typedef

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* architecture dependent typedefs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_FAMILY
end_ifdef

begin_if
if|#
directive|if
name|CPU_FAMILY
operator|==
name|MC680X0
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|INSTR
typedef|;
end_typedef

begin_comment
comment|/* word-aligned instructions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_FAMILY==MC680X0 */
end_comment

begin_if
if|#
directive|if
name|CPU_FAMILY
operator|==
name|SPARC
end_if

begin_typedef
typedef|typedef
name|unsigned
name|long
name|INSTR
typedef|;
end_typedef

begin_comment
comment|/* 32 bit word-aligned instructions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_FAMILY==SPARC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASMLANGUAGE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCvxTypesh */
end_comment

end_unit

