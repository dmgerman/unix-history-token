begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xalloc.h -- malloc with out-of-memory checking    Copyright (C) 1990-1998, 1999, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|XALLOC_H_
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|8
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NORETURN
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_NORETURN
value|__attribute__ ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Exit value when the requested amount of memory is not available.    It is initialized to EXIT_FAILURE, but the caller may set it to    some other value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xalloc_exit_failure
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If this pointer is non-zero, run the specified function upon each    allocation failure.  It is initialized to zero. */
end_comment

begin_extern
extern|extern void (*xalloc_fail_func
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If XALLOC_FAIL_FUNC is undefined or a function that returns, this    message is output.  It is translated via gettext.    Its value is "memory exhausted".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
name|xalloc_msg_memory_exhausted
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is always triggered when memory is exhausted.  It is    in charge of honoring the three previous items.  This is the    function to call when one wants the program to die because of a    memory allocation failure.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|xalloc_die
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|xmalloc
name|PARAMS
argument_list|(
operator|(
name|size_t
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|xcalloc
name|PARAMS
argument_list|(
operator|(
name|size_t
name|n
operator|,
name|size_t
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|xrealloc
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
name|p
operator|,
name|size_t
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xstrdup
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XMALLOC
parameter_list|(
name|Type
parameter_list|,
name|N_items
parameter_list|)
value|((Type *) xmalloc (sizeof (Type) * (N_items)))
end_define

begin_define
define|#
directive|define
name|XCALLOC
parameter_list|(
name|Type
parameter_list|,
name|N_items
parameter_list|)
value|((Type *) xcalloc (sizeof (Type), (N_items)))
end_define

begin_define
define|#
directive|define
name|XREALLOC
parameter_list|(
name|Ptr
parameter_list|,
name|Type
parameter_list|,
name|N_items
parameter_list|)
define|\
value|((Type *) xrealloc ((void *) (Ptr), sizeof (Type) * (N_items)))
end_define

begin_comment
comment|/* Declare and alloc memory for VAR of type TYPE. */
end_comment

begin_define
define|#
directive|define
name|NEW
parameter_list|(
name|Type
parameter_list|,
name|Var
parameter_list|)
value|Type *(Var) = XMALLOC (Type, 1)
end_define

begin_comment
comment|/* Free VAR only if non NULL. */
end_comment

begin_define
define|#
directive|define
name|XFREE
parameter_list|(
name|Var
parameter_list|)
define|\
value|do {                 \       if (Var)          \         free (Var);     \    } while (0)
end_define

begin_comment
comment|/* Return a pointer to a malloc'ed copy of the array SRC of NUM elements. */
end_comment

begin_define
define|#
directive|define
name|CCLONE
parameter_list|(
name|Src
parameter_list|,
name|Num
parameter_list|)
define|\
value|(memcpy (xmalloc (sizeof (*Src) * (Num)), (Src), sizeof (*Src) * (Num)))
end_define

begin_comment
comment|/* Return a malloc'ed copy of SRC. */
end_comment

begin_define
define|#
directive|define
name|CLONE
parameter_list|(
name|Src
parameter_list|)
value|CCLONE (Src, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XALLOC_H_ */
end_comment

end_unit

