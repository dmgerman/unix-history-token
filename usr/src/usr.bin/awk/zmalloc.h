begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** zmalloc.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	zmalloc.h,v $  * Revision 5.1  91/12/05  07:59:41  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* zmalloc.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ZMALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|ZMALLOC_H
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_STDLIB_H
end_if

begin_decl_stmt
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PTR
name|PROTO
argument_list|(
name|bmalloc
argument_list|,
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|bfree
argument_list|,
operator|(
name|PTR
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PTR
name|PROTO
argument_list|(
name|zrealloc
argument_list|,
operator|(
name|PTR
operator|,
name|unsigned
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ZBLOCKSZ
value|8
end_define

begin_define
define|#
directive|define
name|ZSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|zmalloc
parameter_list|(
name|size
parameter_list|)
value|bmalloc((((unsigned)size)+ZBLOCKSZ-1)>>ZSHIFT)
end_define

begin_define
define|#
directive|define
name|zfree
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|)
value|bfree(p,(((unsigned)size)+ZBLOCKSZ-1)>>ZSHIFT)
end_define

begin_define
define|#
directive|define
name|ZMALLOC
parameter_list|(
name|type
parameter_list|)
value|((type*)zmalloc(sizeof(type)))
end_define

begin_define
define|#
directive|define
name|ZFREE
parameter_list|(
name|p
parameter_list|)
value|zfree(p,sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZMALLOC_H */
end_comment

end_unit

