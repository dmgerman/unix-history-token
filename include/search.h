begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: search.h,v 1.12 1999/02/22 10:34:28 christos Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Written by J.T. Conklin<jtc@netbsd.org>  * Public domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SEARCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_SEARCH_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|entry
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|ENTRY
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FIND
block|,
name|ENTER
block|}
name|ACTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|preorder
block|,
name|postorder
block|,
name|endorder
block|,
name|leaf
block|}
name|VISIT
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SEARCH_PRIVATE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|node
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|struct
name|node
modifier|*
name|llink
decl_stmt|,
modifier|*
name|rlink
decl_stmt|;
block|}
name|node_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|int
name|hcreate
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hdestroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ENTRY
modifier|*
name|hsearch
parameter_list|(
name|ENTRY
parameter_list|,
name|ACTION
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tdelete
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tfind
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tsearch
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|twalk
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|VISIT
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SEARCH_H_ */
end_comment

end_unit

