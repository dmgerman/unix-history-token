begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_BYTEORDER_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_BYTEORDER_H
end_define

begin_comment
comment|/* Functions to convert `short' and `long' quantities from host byte order    to (internet) network byte order (i.e. big-endian).     Written by Ron Guilmette (rfg@ncd.com).     This isn't actually used by GCC.  It is installed by fixinc.svr4.     For big-endian machines these functions are essentially no-ops.     For little-endian machines, we define the functions using specialized    asm sequences in cases where doing so yields better code (e.g. i386).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUG__
argument_list|)
end_if

begin_error
error|#
directive|error
error|You lose!  This file is only useful with GNU compilers.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__STATIC
value|static
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__STATIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|__STATIC
name|__inline__
name|unsigned
name|long
name|htonl
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__STATIC
name|__inline__
name|unsigned
name|short
name|htons
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__STATIC
name|__inline__
name|unsigned
name|long
name|ntohl
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__STATIC
name|__inline__
name|unsigned
name|short
name|ntohs
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (__STDC__) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_comment
comment|/* Convert a host long to a network long.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|long
name|htonl
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|long
name|__arg
decl_stmt|;
block|{
specifier|register
name|unsigned
name|long
name|__result
name|__asm__
argument_list|(
literal|"%eax"
argument_list|)
decl_stmt|;
name|__result
operator|=
name|__arg
expr_stmt|;
asm|__asm__ ("xchgb	%%ah, %%al\n\ 	rorl	$16, %%eax\n\ 	xchgb	%%ah, %%al\n\ 	clc" : "=r" (__result) : "0" (__result));
return|return
name|__result
return|;
block|}
end_function

begin_comment
comment|/* Convert a host short to a network short.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|short
name|htons
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|int
name|__arg
decl_stmt|;
block|{
specifier|register
name|unsigned
name|short
name|__result
name|__asm__
argument_list|(
literal|"%eax"
argument_list|)
decl_stmt|;
name|__result
operator|=
name|__arg
expr_stmt|;
asm|__asm__ ("xchgb	%%ah, %%al\n\ 	clc" : "=r" (__result) : "0" (__result));
return|return
name|__result
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
operator|(
operator|(
name|defined
argument_list|(
name|__i860__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__i860_big_endian__
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__ns32k__
argument_list|)
operator|||
name|defined
argument_list|(
name|__vax__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__spur__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|)
end_elif

begin_comment
comment|/* For other little-endian machines, using C code is just as efficient as    using assembly code.  */
end_comment

begin_comment
comment|/* Convert a host long to a network long.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|long
name|htonl
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|long
name|__arg
decl_stmt|;
block|{
specifier|register
name|unsigned
name|long
name|__result
decl_stmt|;
name|__result
operator|=
operator|(
name|__arg
operator|>>
literal|24
operator|)
operator|&
literal|0x000000ff
expr_stmt|;
name|__result
operator||=
operator|(
name|__arg
operator|>>
literal|8
operator|)
operator|&
literal|0x0000ff00
expr_stmt|;
name|__result
operator||=
operator|(
name|__arg
operator|<<
literal|8
operator|)
operator|&
literal|0x00ff0000
expr_stmt|;
name|__result
operator||=
operator|(
name|__arg
operator|<<
literal|24
operator|)
operator|&
literal|0xff000000
expr_stmt|;
return|return
name|__result
return|;
block|}
end_function

begin_comment
comment|/* Convert a host short to a network short.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|short
name|htons
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|int
name|__arg
decl_stmt|;
block|{
specifier|register
name|unsigned
name|short
name|__result
decl_stmt|;
name|__result
operator|=
operator|(
name|__arg
operator|<<
literal|8
operator|)
operator|&
literal|0xff00
expr_stmt|;
name|__result
operator||=
operator|(
name|__arg
operator|>>
literal|8
operator|)
operator|&
literal|0x00ff
expr_stmt|;
return|return
name|__result
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* must be a big-endian machine */
end_comment

begin_comment
comment|/* Convert a host long to a network long.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|long
name|htonl
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|long
name|__arg
decl_stmt|;
block|{
return|return
name|__arg
return|;
block|}
end_function

begin_comment
comment|/* Convert a host short to a network short.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|short
name|htons
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|int
name|__arg
decl_stmt|;
block|{
return|return
name|__arg
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* big-endian */
end_comment

begin_comment
comment|/* Convert a network long to a host long.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|long
name|ntohl
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|long
name|__arg
decl_stmt|;
block|{
return|return
name|htonl
argument_list|(
name|__arg
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Convert a network short to a host short.  */
end_comment

begin_function
name|__STATIC
name|__inline__
name|unsigned
name|short
name|ntohs
parameter_list|(
name|__arg
parameter_list|)
name|unsigned
name|int
name|__arg
decl_stmt|;
block|{
return|return
name|htons
argument_list|(
name|__arg
argument_list|)
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|__STATIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (_SYS_BYTEORDER_H) */
end_comment

end_unit

