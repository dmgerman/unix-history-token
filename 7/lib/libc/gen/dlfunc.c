begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source file is in the public domain.  * Garrett A. Wollman, 2002-05-28.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<dlfcn.h>
end_include

begin_comment
comment|/*  * Implement the dlfunc() interface, which behaves exactly the same as  * dlsym() except that it returns a function pointer instead of a data  * pointer.  This can be used by applications to avoid compiler warnings  * about undefined behavior, and is intended as prior art for future  * POSIX standardization.  This function requires that all pointer types  * have the same representation, which is true on all platforms FreeBSD  * runs on, but is not guaranteed by the C standard.  */
end_comment

begin_function
name|dlfunc_t
name|dlfunc
parameter_list|(
name|void
modifier|*
name|__restrict
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|symbol
parameter_list|)
block|{
union|union
block|{
name|void
modifier|*
name|d
decl_stmt|;
name|dlfunc_t
name|f
decl_stmt|;
block|}
name|rv
union|;
name|rv
operator|.
name|d
operator|=
name|dlsym
argument_list|(
name|handle
argument_list|,
name|symbol
argument_list|)
expr_stmt|;
return|return
operator|(
name|rv
operator|.
name|f
operator|)
return|;
block|}
end_function

end_unit

