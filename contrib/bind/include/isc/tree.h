begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tree.h - declare structures used by tree library  *  * vix 22jan93 [revisited; uses RCS, ANSI, POSIX; has bug fixes]  * vix 27jun86 [broken out of tree.c]  *  * $Id: tree.h,v 8.2 1996/10/25 18:11:03 vixie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TREE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_TREE_H_INCLUDED
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|x
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

begin_comment
comment|/*  * tree_t is our package-specific anonymous pointer.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|tree_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|tree_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|tree_s
block|{
name|tree_t
name|data
decl_stmt|;
name|struct
name|tree_s
modifier|*
name|left
decl_stmt|,
modifier|*
name|right
decl_stmt|;
name|short
name|bal
decl_stmt|;
block|}
name|tree
typedef|;
end_typedef

begin_decl_stmt
name|void
name|tree_init
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree_t
name|tree_srch
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|tree_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|tree_t
name|tree_add
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|tree_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tree_delete
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|tree_t
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tree_trav
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tree_mung
name|__P
argument_list|(
operator|(
name|tree
operator|*
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TREE_H_INCLUDED */
end_comment

end_unit

