begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unwind_prot.h - Macros and functions for hacking unwind protection. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_UNWIND_PROT_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_UNWIND_PROT_H
end_define

begin_comment
comment|/* Run a function without interrupts. */
end_comment

begin_decl_stmt
name|void
name|without_interrupts
argument_list|()
decl_stmt|,
name|begin_unwind_frame
argument_list|()
decl_stmt|,
name|discard_unwind_frame
argument_list|()
decl_stmt|,
name|run_unwind_frame
argument_list|()
decl_stmt|,
name|add_unwind_protect
argument_list|()
decl_stmt|,
name|remove_unwind_protect
argument_list|()
decl_stmt|,
name|run_unwind_protects
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define for people who like their code to look a certain way. */
end_comment

begin_define
define|#
directive|define
name|end_unwind_frame
parameter_list|()
end_define

begin_comment
comment|/* How to protect an integer. */
end_comment

begin_define
define|#
directive|define
name|unwind_protect_int
parameter_list|(
name|X
parameter_list|)
value|unwind_protect_var (&(X), (X), sizeof (int))
end_define

begin_comment
comment|/* How to protect a pointer to a string. */
end_comment

begin_define
define|#
directive|define
name|unwind_protect_string
parameter_list|(
name|X
parameter_list|)
define|\
value|unwind_protect_var (&(X), (X), sizeof (char *))
end_define

begin_comment
comment|/* How to protect any old pointer. */
end_comment

begin_define
define|#
directive|define
name|unwind_protect_pointer
parameter_list|(
name|X
parameter_list|)
value|unwind_protect_string (X)
end_define

begin_comment
comment|/* How to protect the contents of a jmp_buf. */
end_comment

begin_define
define|#
directive|define
name|unwind_protect_jmp_buf
parameter_list|(
name|X
parameter_list|)
define|\
value|unwind_protect_var ((int *)(X), (char *)(X), sizeof (jmp_buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNWIND_PROT_H */
end_comment

end_unit

