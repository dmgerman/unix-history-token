begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Annotation.h - Annotation classes ----------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file contains the declarations for two classes: Annotation& Annotable.
end_comment

begin_comment
comment|// Using these two simple classes, anything that derives from Annotable can have
end_comment

begin_comment
comment|// Annotation subclasses attached to them, ready for easy retrieval.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Annotations are designed to be easily attachable to various classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The AnnotationManager class is essential for using these classes.  It is
end_comment

begin_comment
comment|// responsible for turning Annotation name strings into tokens [unique id #'s]
end_comment

begin_comment
comment|// that may be used to search for and create annotations.
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
name|LLVM_SUPPORT_ANNOTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ANNOTATION_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AnnotationID
decl_stmt|;
name|class
name|Annotation
decl_stmt|;
name|class
name|Annotable
decl_stmt|;
struct_decl|struct
name|AnnotationManager
struct_decl|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// AnnotationID - This class is a thin wrapper around an unsigned integer that
comment|// is used to hopefully prevent errors using AnnotationID's.  They may be copied
comment|// freely around and passed byvalue with little or no overhead.
comment|//
name|class
name|AnnotationID
block|{
name|friend
struct_decl|struct
name|AnnotationManager
struct_decl|;
name|unsigned
name|ID
decl_stmt|;
name|AnnotationID
argument_list|()
expr_stmt|;
comment|// Default ctor is disabled
comment|// AnnotationID is only creatable from AnnMgr.
name|explicit
specifier|inline
name|AnnotationID
argument_list|(
argument|unsigned i
argument_list|)
operator|:
name|ID
argument_list|(
argument|i
argument_list|)
block|{}
name|public
operator|:
specifier|inline
name|AnnotationID
argument_list|(
specifier|const
name|AnnotationID
operator|&
name|A
argument_list|)
operator|:
name|ID
argument_list|(
argument|A.ID
argument_list|)
block|{}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|AnnotationID
operator|&
name|A
operator|)
specifier|const
block|{
return|return
name|A
operator|.
name|ID
operator|==
name|ID
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|AnnotationID
operator|&
name|A
operator|)
specifier|const
block|{
return|return
name|ID
operator|<
name|A
operator|.
name|ID
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Annotation Class - This class serves as a base class for any specific
comment|// annotations that you might need.  Simply subclass this to add extra
comment|// information to the annotations.
comment|//
name|class
name|Annotation
block|{
name|friend
name|class
name|Annotable
decl_stmt|;
comment|// Annotable manipulates Next list
name|AnnotationID
name|ID
decl_stmt|;
comment|// ID number, as obtained from AnnotationManager
name|Annotation
modifier|*
name|Next
decl_stmt|;
comment|// The next annotation in the linked list
name|public
label|:
name|explicit
specifier|inline
name|Annotation
argument_list|(
argument|AnnotationID id
argument_list|)
operator|:
name|ID
argument_list|(
name|id
argument_list|)
operator|,
name|Next
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|Annotation
argument_list|()
expr_stmt|;
comment|// Designed to be subclassed
comment|// getID - Return the unique ID# of this annotation
specifier|inline
name|AnnotationID
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
comment|// getNext - Return the next annotation in the list...
specifier|inline
name|Annotation
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|Next
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// Annotable - This class is used as a base class for all objects that would
comment|// like to have annotation capability.
comment|//
comment|// Annotable objects keep their annotation list sorted as annotations are
comment|// inserted and deleted.  This is used to ensure that annotations with identical
comment|// ID#'s are stored sequentially.
comment|//
name|class
name|Annotable
block|{
name|mutable
name|Annotation
modifier|*
name|AnnotationList
decl_stmt|;
name|Annotable
argument_list|(
specifier|const
name|Annotable
operator|&
argument_list|)
expr_stmt|;
comment|// Do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|Annotable
operator|&
operator|)
decl_stmt|;
comment|// Do not implement
name|public
label|:
name|Annotable
argument_list|()
operator|:
name|AnnotationList
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|Annotable
argument_list|()
expr_stmt|;
comment|// getAnnotation - Search the list for annotations of the specified ID.  The
comment|// pointer returned is either null (if no annotations of the specified ID
comment|// exist), or it points to the first element of a potentially list of elements
comment|// with identical ID #'s.
comment|//
name|Annotation
modifier|*
name|getAnnotation
argument_list|(
name|AnnotationID
name|ID
argument_list|)
decl|const
block|{
for|for
control|(
name|Annotation
modifier|*
name|A
init|=
name|AnnotationList
init|;
name|A
condition|;
name|A
operator|=
name|A
operator|->
name|getNext
argument_list|()
control|)
if|if
condition|(
name|A
operator|->
name|getID
argument_list|()
operator|==
name|ID
condition|)
return|return
name|A
return|;
return|return
literal|0
return|;
block|}
comment|// getOrCreateAnnotation - Search through the annotation list, if there is
comment|// no annotation with the specified ID, then use the AnnotationManager to
comment|// create one.
comment|//
specifier|inline
name|Annotation
modifier|*
name|getOrCreateAnnotation
argument_list|(
name|AnnotationID
name|ID
argument_list|)
decl|const
decl_stmt|;
comment|// addAnnotation - Insert the annotation into the list in a sorted location.
comment|//
name|void
name|addAnnotation
argument_list|(
name|Annotation
operator|*
name|A
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|A
operator|->
name|Next
operator|==
literal|0
operator|&&
literal|"Annotation already in list?!?"
argument_list|)
expr_stmt|;
name|Annotation
modifier|*
modifier|*
name|AL
init|=
operator|&
name|AnnotationList
decl_stmt|;
while|while
condition|(
operator|*
name|AL
operator|&&
operator|(
operator|*
name|AL
operator|)
operator|->
name|ID
operator|<
name|A
operator|->
name|getID
argument_list|()
condition|)
comment|// Find where to insert annotation
name|AL
operator|=
operator|&
operator|(
operator|(
operator|*
name|AL
operator|)
operator|->
name|Next
operator|)
expr_stmt|;
name|A
operator|->
name|Next
operator|=
operator|*
name|AL
expr_stmt|;
comment|// Link the annotation in
operator|*
name|AL
operator|=
name|A
expr_stmt|;
block|}
comment|// unlinkAnnotation - Remove the first annotation of the specified ID... and
comment|// then return the unlinked annotation.  The annotation object is not deleted.
comment|//
specifier|inline
name|Annotation
modifier|*
name|unlinkAnnotation
argument_list|(
name|AnnotationID
name|ID
argument_list|)
decl|const
block|{
for|for
control|(
name|Annotation
modifier|*
modifier|*
name|A
init|=
operator|&
name|AnnotationList
init|;
operator|*
name|A
condition|;
name|A
operator|=
operator|&
operator|(
operator|(
operator|*
name|A
operator|)
operator|->
name|Next
operator|)
control|)
if|if
condition|(
operator|(
operator|*
name|A
operator|)
operator|->
name|getID
argument_list|()
operator|==
name|ID
condition|)
block|{
name|Annotation
modifier|*
name|Ret
init|=
operator|*
name|A
decl_stmt|;
operator|*
name|A
operator|=
name|Ret
operator|->
name|Next
expr_stmt|;
name|Ret
operator|->
name|Next
operator|=
literal|0
expr_stmt|;
return|return
name|Ret
return|;
block|}
return|return
literal|0
return|;
block|}
comment|// deleteAnnotation - Delete the first annotation of the specified ID in the
comment|// list.  Unlink unlinkAnnotation, this actually deletes the annotation object
comment|//
name|bool
name|deleteAnnotation
argument_list|(
name|AnnotationID
name|ID
argument_list|)
decl|const
block|{
name|Annotation
modifier|*
name|A
init|=
name|unlinkAnnotation
argument_list|(
name|ID
argument_list|)
decl_stmt|;
name|delete
name|A
decl_stmt|;
return|return
name|A
operator|!=
literal|0
return|;
block|}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|//
comment|// AnnotationManager - This class is primarily responsible for maintaining a
comment|// one-to-one mapping between string Annotation names and Annotation ID numbers.
comment|//
comment|// Compared to the rest of the Annotation system, these mapping methods are
comment|// relatively slow, so they should be avoided by locally caching Annotation
comment|// ID #'s.  These methods are safe to call at any time, even by static ctors, so
comment|// they should be used by static ctors most of the time.
comment|//
comment|// This class also provides support for annotations that are created on demand
comment|// by the Annotable::getOrCreateAnnotation method.  To get this to work, simply
comment|// register an annotation handler
comment|//
struct|struct
name|AnnotationManager
block|{
typedef|typedef
name|Annotation
modifier|*
function_decl|(
modifier|*
name|Factory
function_decl|)
parameter_list|(
name|AnnotationID
parameter_list|,
specifier|const
name|Annotable
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Basic ID<-> Name map functionality
specifier|static
name|AnnotationID
name|getID
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|// Name -> ID
specifier|static
specifier|const
name|char
modifier|*
name|getName
parameter_list|(
name|AnnotationID
name|ID
parameter_list|)
function_decl|;
comment|// ID -> Name
comment|// getID - Name -> ID + registration of a factory function for demand driven
comment|// annotation support.
specifier|static
name|AnnotationID
name|getID
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
name|Factory
name|Fact
parameter_list|,
name|void
modifier|*
name|Data
init|=
literal|0
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Annotation creation on demand support...
comment|// registerAnnotationFactory - This method is used to register a callback
comment|// function used to create an annotation on demand if it is needed by the
comment|// Annotable::getOrCreateAnnotation method.
comment|//
specifier|static
name|void
name|registerAnnotationFactory
parameter_list|(
name|AnnotationID
name|ID
parameter_list|,
name|Factory
name|Func
parameter_list|,
name|void
modifier|*
name|ExtraData
init|=
literal|0
parameter_list|)
function_decl|;
comment|// createAnnotation - Create an annotation of the specified ID for the
comment|// specified object, using a register annotation creation function.
comment|//
specifier|static
name|Annotation
modifier|*
name|createAnnotation
parameter_list|(
name|AnnotationID
name|ID
parameter_list|,
specifier|const
name|Annotable
modifier|*
name|Obj
parameter_list|)
function_decl|;
block|}
struct|;
comment|// getOrCreateAnnotation - Search through the annotation list, if there is
comment|// no annotation with the specified ID, then use the AnnotationManager to
comment|// create one.
comment|//
specifier|inline
name|Annotation
operator|*
name|Annotable
operator|::
name|getOrCreateAnnotation
argument_list|(
argument|AnnotationID ID
argument_list|)
specifier|const
block|{
name|Annotation
operator|*
name|A
operator|=
name|getAnnotation
argument_list|(
name|ID
argument_list|)
block|;
comment|// Fast path, check for preexisting ann
if|if
condition|(
name|A
condition|)
return|return
name|A
return|;
comment|// No annotation found, ask the annotation manager to create an annotation...
name|A
operator|=
name|AnnotationManager
operator|::
name|createAnnotation
argument_list|(
name|ID
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|A
operator|&&
literal|"AnnotationManager could not create annotation!"
argument_list|)
expr_stmt|;
name|addAnnotation
argument_list|(
name|A
argument_list|)
expr_stmt|;
return|return
name|A
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

