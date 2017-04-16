begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple i386-apple-darwin10 -w -analyzer-checker=osx.NumberObjectConversion %s -verify
end_comment

begin_comment
comment|// RUN: %clang_analyze_cc1 -triple i386-apple-darwin10 -w -analyzer-checker=osx.NumberObjectConversion -analyzer-config osx.NumberObjectConversion:Pedantic=true -DPEDANTIC %s -verify
end_comment

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFNumber
modifier|*
name|CFNumberRef
typedef|;
end_typedef

begin_function_decl
name|void
name|takes_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|bad
parameter_list|(
name|CFNumberRef
name|p
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|PEDANTIC
if|if
condition|(
name|p
condition|)
block|{}
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive boolean value; instead, either compare the pointer to NULL or call CFNumberGetValue()}}
if|if
condition|(
operator|!
name|p
condition|)
block|{}
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive boolean value; instead, either compare the pointer to NULL or call CFNumberGetValue()}}
name|p
condition|?
literal|1
else|:
literal|2
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive boolean value; instead, either compare the pointer to NULL or call CFNumberGetValue()}}
if|if
condition|(
name|p
operator|==
literal|0
condition|)
block|{}
comment|// expected-warning{{Comparing a pointer value of type 'CFNumberRef' to a primitive integer value; instead, either compare the pointer to NULL or compare the result of calling CFNumberGetValue()}}
else|#
directive|else
if|if
condition|(
name|p
condition|)
block|{}
comment|// no-warning
if|if
condition|(
operator|!
name|p
condition|)
block|{}
comment|// no-warning
name|p
condition|?
literal|1
else|:
literal|2
expr_stmt|;
comment|// no-warning
if|if
condition|(
name|p
operator|==
literal|0
condition|)
block|{}
comment|// no-warning
endif|#
directive|endif
if|if
condition|(
name|p
operator|>
literal|0
condition|)
block|{}
comment|// expected-warning{{Comparing a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to compare the result of calling CFNumberGetValue()?}}
name|int
name|x
init|=
name|p
decl_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
name|x
operator|=
name|p
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
name|takes_int
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
name|takes_int
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Conversion of a pointer to an intptr_t is fine.
end_comment

begin_typedef
typedef|typedef
name|long
name|intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|fintptr_t
typedef|;
end_typedef

begin_comment
comment|// Fake, for testing the regex.
end_comment

begin_function
name|void
name|test_intptr_t
parameter_list|(
name|CFNumberRef
name|p
parameter_list|)
block|{
operator|(
name|long
operator|)
name|p
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
operator|(
name|intptr_t
operator|)
name|p
expr_stmt|;
comment|// no-warning
operator|(
name|unsigned
name|long
operator|)
name|p
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
operator|(
name|uintptr_t
operator|)
name|p
expr_stmt|;
comment|// no-warning
operator|(
name|fintptr_t
operator|)
name|p
expr_stmt|;
comment|// expected-warning{{Converting a pointer value of type 'CFNumberRef' to a primitive integer value; did you mean to call CFNumberGetValue()?}}
block|}
end_function

end_unit

