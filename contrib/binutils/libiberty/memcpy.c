begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memcpy (the standard C function)    This function is in the public domain.  */
end_comment

begin_comment
comment|/* NAME 	memcpy -- copy memory regions of arbitary length  SYNOPSIS 	void* memcpy (void *out, const void *in, size_t n);  DESCRIPTION 	Copy LENGTH bytes from memory region pointed to by IN to memory 	region pointed to by OUT. */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PTR
name|DEFUN
argument_list|(
name|memcpy
argument_list|,
operator|(
name|out
operator|,
name|in
operator|,
name|length
operator|)
argument_list|,
name|PTR
name|out
name|AND
specifier|const
name|PTR
name|in
name|AND
name|size_t
name|length
argument_list|)
block|{
name|bcopy
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_decl_stmt

end_unit

