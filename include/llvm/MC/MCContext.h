begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCContext.h - Machine Code Context -----------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCValue
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// MCContext - Context object for machine code objects.  This class owns all
comment|/// of the sections that it creates.
comment|///
name|class
name|MCContext
block|{
name|MCContext
argument_list|(
specifier|const
name|MCContext
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|MCContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCContext
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
comment|/// Sections - Bindings of names to allocated sections.
name|StringMap
operator|<
name|MCSection
operator|*
operator|>
name|Sections
expr_stmt|;
comment|/// Symbols - Bindings of names to symbols.
name|StringMap
operator|<
name|MCSymbol
operator|*
operator|>
name|Symbols
expr_stmt|;
comment|/// SymbolValues - Bindings of symbols to values.
comment|//
comment|// FIXME: Is there a good reason to not just put this in the MCSymbol?
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
operator|,
name|MCValue
operator|>
name|SymbolValues
expr_stmt|;
comment|/// Allocator - Allocator object used for creating machine code objects.
comment|///
comment|/// We use a bump pointer allocator to avoid the need to track all allocated
comment|/// objects.
name|BumpPtrAllocator
name|Allocator
decl_stmt|;
name|public
label|:
name|MCContext
argument_list|()
expr_stmt|;
operator|~
name|MCContext
argument_list|()
expr_stmt|;
comment|/// @name Symbol Managment
comment|/// @{
comment|/// CreateSymbol - Create a new symbol with the specified @param Name.
comment|///
comment|/// @param Name - The symbol name, which must be unique across all symbols.
name|MCSymbol
modifier|*
name|CreateSymbol
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|Name
parameter_list|)
function_decl|;
comment|/// GetOrCreateSymbol - Lookup the symbol inside with the specified
comment|/// @param Name.  If it exists, return it.  If not, create a forward
comment|/// reference and return it.
comment|///
comment|/// @param Name - The symbol name, which must be unique across all symbols.
comment|/// @param IsTemporary - Whether this symbol is an assembler temporary,
comment|/// which should not survive into the symbol table for the translation unit.
name|MCSymbol
modifier|*
name|GetOrCreateSymbol
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|Name
parameter_list|)
function_decl|;
comment|/// CreateTemporarySymbol - Create a new temporary symbol with the specified
comment|/// @param Name.
comment|///
comment|/// @param Name - The symbol name, for debugging purposes only, temporary
comment|/// symbols do not surive assembly. If non-empty the name must be unique
comment|/// across all symbols.
name|MCSymbol
modifier|*
name|CreateTemporarySymbol
parameter_list|(
specifier|const
name|StringRef
modifier|&
name|Name
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// LookupSymbol - Get the symbol for @param Name, or null.
name|MCSymbol
modifier|*
name|LookupSymbol
argument_list|(
specifier|const
name|StringRef
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Symbol Value Table
comment|/// @{
comment|/// ClearSymbolValue - Erase a value binding for @arg Symbol, if one exists.
name|void
name|ClearSymbolValue
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|)
function_decl|;
comment|/// SetSymbolValue - Set the value binding for @arg Symbol to @arg Value.
name|void
name|SetSymbolValue
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|Symbol
parameter_list|,
specifier|const
name|MCValue
modifier|&
name|Value
parameter_list|)
function_decl|;
comment|/// GetSymbolValue - Return the current value for @arg Symbol, or null if
comment|/// none exists.
specifier|const
name|MCValue
modifier|*
name|GetSymbolValue
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Symbol
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
name|void
modifier|*
name|Allocate
parameter_list|(
name|unsigned
name|Size
parameter_list|,
name|unsigned
name|Align
init|=
literal|8
parameter_list|)
block|{
return|return
name|Allocator
operator|.
name|Allocate
argument_list|(
name|Size
argument_list|,
name|Align
argument_list|)
return|;
block|}
name|void
name|Deallocate
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{      }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_comment
comment|// operator new and delete aren't allowed inside namespaces.
end_comment

begin_comment
comment|// The throw specifications are mandated by the standard.
end_comment

begin_comment
comment|/// @brief Placement new for using the MCContext's allocator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This placement form of operator new uses the MCContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new, which means that it returns
end_comment

begin_comment
comment|/// null on error. (If that is what the allocator does. The current does, so if
end_comment

begin_comment
comment|/// this ever changes, this operator will have to be changed, too.)
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an MCContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// IntegerLiteral *Ex = new (Context) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// IntegerLiteral *Ex2 = new (Context, 8) IntegerLiteral(arguments);
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|16
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete companion to the new above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new expression using
end_comment

begin_comment
comment|/// the MCContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// This placement form of operator new[] uses the MCContext's allocator for
end_comment

begin_comment
comment|/// obtaining memory. It is a non-throwing new[], which means that it returns
end_comment

begin_comment
comment|/// null on error.
end_comment

begin_comment
comment|/// Usage looks like this (assuming there's an MCContext 'Context' in scope):
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// // Default alignment (16)
end_comment

begin_comment
comment|/// char *data = new (Context) char[10];
end_comment

begin_comment
comment|/// // Specific alignment
end_comment

begin_comment
comment|/// char *data = new (Context, 8) char[10];
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|/// Please note that you cannot use delete on the pointer; it must be
end_comment

begin_comment
comment|/// deallocated using an explicit destructor call followed by
end_comment

begin_comment
comment|/// @c Context.Deallocate(Ptr).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Bytes The number of bytes to allocate. Calculated by the compiler.
end_comment

begin_comment
comment|/// @param C The MCContext that provides the allocator.
end_comment

begin_comment
comment|/// @param Alignment The alignment of the allocated memory (if the underlying
end_comment

begin_comment
comment|///                  allocator supports it).
end_comment

begin_comment
comment|/// @return The allocated memory. Could be NULL.
end_comment

begin_decl_stmt
specifier|inline
name|void
modifier|*
name|operator
name|new
index|[]
argument_list|(
name|size_t
name|Bytes
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|,
name|size_t
name|Alignment
operator|=
literal|16
argument_list|)
name|throw
argument_list|()
block|{
return|return
name|C
operator|.
name|Allocate
argument_list|(
name|Bytes
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Placement delete[] companion to the new[] above.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This operator is just a companion to the new[] above. There is no way of
end_comment

begin_comment
comment|/// invoking it directly; see the new[] operator for more details. This operator
end_comment

begin_comment
comment|/// is called implicitly by the compiler if a placement new[] expression using
end_comment

begin_comment
comment|/// the MCContext throws in the object constructor.
end_comment

begin_decl_stmt
specifier|inline
name|void
name|operator
name|delete
index|[]
argument_list|(
name|void
operator|*
name|Ptr
argument_list|,
name|llvm
operator|::
name|MCContext
operator|&
name|C
argument_list|)
name|throw
argument_list|()
block|{
name|C
operator|.
name|Deallocate
argument_list|(
name|Ptr
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

