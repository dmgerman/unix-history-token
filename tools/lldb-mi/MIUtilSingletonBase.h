begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilSingletonBase.h -----------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:        MIUtilSingletonBase.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    MI::ISingleton interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
end_comment

begin_comment
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_decl_stmt
name|namespace
name|MI
block|{
comment|//   MI::ISingleton base class usage:
comment|//
comment|//   class CMIDerivedClass
comment|//       : public MI::ISingleton< CMIDerivedClass>
comment|//   {
comment|//       friend MI::ISingleton< CMIDerivedClass>;
comment|//
comment|//   // Overridden:
comment|//   public:
comment|//       // From MI::ISingleton
comment|//       virtual bool Initialize( void );
comment|//       virtual bool Shutdown( void );
comment|//   };
comment|//++ ============================================================================
comment|// Details: Base class for the singleton pattern.
comment|// Gotchas: Derived class must specify MI::ISingleton<> as a friend class.
comment|// Authors: Aidan Dodds 17/03/2014.
comment|// Changes: None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ISingleton
block|{
comment|// Statics:
name|public
operator|:
comment|// Return an instance of the derived class
specifier|static
name|T
operator|&
name|Instance
argument_list|(
argument|void
argument_list|)
block|{
comment|// This will fail if the derived class has not
comment|// declared itself to be a friend of MI::ISingleton
specifier|static
name|T
name|instance
block|;
return|return
name|instance
return|;
block|}
comment|// Overrideable:
name|public
operator|:
name|virtual
name|bool
name|Initialize
argument_list|(
name|void
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|Shutdown
argument_list|(
name|void
argument_list|)
operator|=
literal|0
block|;
comment|//
comment|/* dtor */
name|virtual
operator|~
name|ISingleton
argument_list|(
argument|void
argument_list|)
block|{}
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace MI
end_comment

end_unit

