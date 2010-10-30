begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// target-select.h -- select a target for an object file  -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_TARGET_SELECT_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_TARGET_SELECT_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Target
decl_stmt|;
comment|// We want to avoid a master list of targets, which implies using a
comment|// global constructor.  And we also want the program to start up as
comment|// quickly as possible, which implies avoiding global constructors.
comment|// We compromise on a very simple global constructor.  We use a target
comment|// selector, which specifies an ELF machine number and a recognition
comment|// function.  We use global constructors to build a linked list of
comment|// target selectors--a simple pointer list, not a std::list.
name|class
name|Target_selector
block|{
name|public
label|:
comment|// Create a target selector for a specific machine number, size (32
comment|// or 64), and endianness.  The machine number can be EM_NONE to
comment|// test for any machine number.
name|Target_selector
argument_list|(
argument|int machine
argument_list|,
argument|int size
argument_list|,
argument|bool big_endian
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|Target_selector
argument_list|()
block|{ }
comment|// If we can handle this target, return a pointer to a target
comment|// structure.  The size and endianness are known.
name|virtual
name|Target
operator|*
name|recognize
argument_list|(
argument|int machine
argument_list|,
argument|int osabi
argument_list|,
argument|int abiversion
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|// Return the next Target_selector in the linked list.
name|Target_selector
operator|*
name|next
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|next_
return|;
block|}
comment|// Return the machine number this selector is looking for, which can
comment|// be EM_NONE to match any machine number.
name|int
name|machine
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|machine_
return|;
block|}
comment|// Return the size this is looking for (32 or 64).
name|int
name|size
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|size_
return|;
block|}
comment|// Return the endianness this is looking for.
name|bool
name|big_endian
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|big_endian_
return|;
block|}
name|private
label|:
name|int
name|machine_
decl_stmt|;
name|int
name|size_
decl_stmt|;
name|bool
name|big_endian_
decl_stmt|;
name|Target_selector
modifier|*
name|next_
decl_stmt|;
block|}
empty_stmt|;
comment|// Select the target for an ELF file.
specifier|extern
name|Target
modifier|*
name|select_target
parameter_list|(
name|int
name|machine
parameter_list|,
name|int
name|size
parameter_list|,
name|bool
name|big_endian
parameter_list|,
name|int
name|osabi
parameter_list|,
name|int
name|abiversion
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_TARGET_SELECT_H)
end_comment

end_unit

