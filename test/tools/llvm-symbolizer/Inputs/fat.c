begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compile with:    clang -arch armv7 -arch armv7m -arch armv7em -arch x86_64 -arch x86_64h -c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64h__
end_ifdef

begin_function
name|void
name|x86_64h_function
parameter_list|()
block|{}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_function
name|void
name|x86_64_function
parameter_list|()
block|{}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7EM__
argument_list|)
end_elif

begin_function
name|void
name|armv7em_function
parameter_list|()
block|{}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7M__
argument_list|)
end_elif

begin_function
name|void
name|armv7m_function
parameter_list|()
block|{}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_elif

begin_function
name|void
name|armv7_function
parameter_list|()
block|{}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

