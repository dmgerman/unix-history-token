begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|eGetOpt_h
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_define
define|#
directive|define
name|eGetOpt_h
value|1
end_define

begin_include
include|#
directive|include
file|<GetOpt.h>
end_include

begin_include
include|#
directive|include
file|<String.h>
end_include

begin_comment
comment|// eGetOpt is a subclass of GetOpt which provides functions for
end_comment

begin_comment
comment|// handling arguments to the options.
end_comment

begin_decl_stmt
name|class
name|eGetOpt
range|:
name|public
name|GetOpt
block|{
name|public
operator|:
name|eGetOpt
argument_list|(
argument|int argc
argument_list|,
argument|char **argv
argument_list|,
argument|char *optstring
argument_list|)
operator|:
name|GetOpt
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|,
argument|optstring
argument_list|)
block|{}
comment|// first_char returns the first character of the argument.
name|int
name|first_char
argument_list|()
block|{
return|return
name|nargv
index|[
name|optind
index|]
index|[
literal|0
index|]
return|;
block|}
block|;
comment|// next_arg looks at next argument for an interger, double or string
comment|// depending on the type of argument given to it. If the correct type is
comment|// found, the value is set and next_arg returns 1.  If the type is not
comment|// correct, next_arg returns 0.
comment|// double arguments start with a digit, plus, minus or period.
comment|// integer arguments start with a digit.
comment|// String arguments have no restriction.
comment|// If the next argument is an integer, set the reference variable to it
comment|// and increment the index to the options.  Return 1 if an integer is
comment|// found, else return 0.
name|int
name|next_arg
argument_list|(
name|int
operator|&
name|i
argument_list|)
block|;
name|int
name|next_arg
argument_list|(
name|double
operator|&
name|d
argument_list|)
block|;
name|int
name|next_arg
argument_list|(
name|String
operator|&
name|s
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

