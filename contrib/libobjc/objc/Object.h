begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for the Object class for Objective-C.    Copyright (C) 1993, 1994, 1995 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled    with GCC to produce an executable, this does not cause the resulting    executable to be covered by the GNU General Public License.  This    exception does not however invalidate any other reasons why the    executable file might be covered by the GNU General Public License. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__object_INCLUDE_GNU
end_ifndef

begin_define
define|#
directive|define
name|__object_INCLUDE_GNU
end_define

begin_include
include|#
directive|include
file|<objc/objc.h>
end_include

begin_include
include|#
directive|include
file|<objc/typedstream.h>
end_include

begin_comment
comment|/*  * All classes are derived from Object.  As such,  * this is the overhead tacked onto those objects.  */
end_comment

begin_decl_stmt
unit|@
name|interface
name|Object
block|{
name|Class
name|isa
decl_stmt|;
comment|/* A pointer to the instance's class structure */
block|}
end_decl_stmt

begin_comment
comment|/* Initializing classes and instances */
end_comment

begin_expr_stmt
operator|+
name|initialize
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|init
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Creating, freeing, and copying instances */
end_comment

begin_expr_stmt
operator|+
name|new
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
name|alloc
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|free
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|copy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|shallowCopy
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|deepen
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|deepCopy
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Identifying classes */
end_comment

begin_expr_stmt
operator|-
operator|(
name|Class
operator|)
name|class
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|Class
operator|)
name|superClass
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|MetaClass
operator|)
name|metaClass
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
specifier|const
name|char
operator|*
operator|)
name|name
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Identifying and comparing objects */
end_comment

begin_expr_stmt
operator|-
name|self
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|unsigned
name|int
operator|)
name|hash
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isEqual
operator|:
name|anObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|int
operator|)
name|compare
operator|:
name|anotherObject
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Testing object type */
end_comment

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isMetaClass
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isClass
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isInstance
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Testing inheritance relationships */
end_comment

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isKindOf
operator|:
operator|(
name|Class
operator|)
name|aClassObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isMemberOf
operator|:
operator|(
name|Class
operator|)
name|aClassObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isKindOfClassNamed
operator|:
operator|(
specifier|const
name|char
operator|*
operator|)
name|aClassName
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|isMemberOfClassNamed
operator|:
operator|(
specifier|const
name|char
operator|*
operator|)
name|aClassName
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Testing class functionality */
end_comment

begin_expr_stmt
operator|+
operator|(
name|BOOL
operator|)
name|instancesRespondTo
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|respondsTo
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Testing protocol conformance */
end_comment

begin_expr_stmt
operator|-
operator|(
name|BOOL
operator|)
name|conformsTo
operator|:
operator|(
name|Protocol
operator|*
operator|)
name|aProtocol
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Introspection */
end_comment

begin_expr_stmt
operator|+
operator|(
name|IMP
operator|)
name|instanceMethodFor
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|IMP
operator|)
name|methodFor
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
expr|struct
name|objc_method_description
operator|*
operator|)
name|descriptionForInstanceMethod
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
expr|struct
name|objc_method_description
operator|*
operator|)
name|descriptionForMethod
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Sending messages determined at run time */
end_comment

begin_expr_stmt
operator|-
name|perform
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|perform
operator|:
operator|(
name|SEL
operator|)
name|aSel
name|with
operator|:
name|anObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|perform
operator|:
operator|(
name|SEL
operator|)
name|aSel
name|with
operator|:
name|anObject1
name|with
operator|:
name|anObject2
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Forwarding */
end_comment

begin_expr_stmt
operator|-
operator|(
name|retval_t
operator|)
name|forward
operator|:
operator|(
name|SEL
operator|)
name|aSel
operator|:
operator|(
name|arglist_t
operator|)
name|argFrame
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|retval_t
operator|)
name|performv
operator|:
operator|(
name|SEL
operator|)
name|aSel
operator|:
operator|(
name|arglist_t
operator|)
name|argFrame
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Posing */
end_comment

begin_expr_stmt
operator|+
name|poseAs
operator|:
operator|(
name|Class
operator|)
name|aClassObject
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
operator|(
name|Class
operator|)
name|transmuteClassTo
operator|:
operator|(
name|Class
operator|)
name|aClassObject
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Enforcing intentions */
end_comment

begin_expr_stmt
operator|-
name|subclassResponsibility
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|notImplemented
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|shouldNotImplement
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Error handling */
end_comment

begin_expr_stmt
operator|-
name|doesNotRecognize
operator|:
operator|(
name|SEL
operator|)
name|aSel
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|error
operator|:
operator|(
specifier|const
name|char
operator|*
operator|)
name|aString
operator|,
operator|...
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Archiving */
end_comment

begin_expr_stmt
operator|+
operator|(
name|int
operator|)
name|version
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
name|setVersion
operator|:
operator|(
name|int
operator|)
name|aVersion
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|+
operator|(
name|int
operator|)
name|streamVersion
operator|:
operator|(
name|TypedStream
operator|*
operator|)
name|aStream
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|read
operator|:
operator|(
name|TypedStream
operator|*
operator|)
name|aStream
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|write
operator|:
operator|(
name|TypedStream
operator|*
operator|)
name|aStream
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|-
name|awake
expr_stmt|;
end_expr_stmt

begin_macro
unit|@
name|end
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

