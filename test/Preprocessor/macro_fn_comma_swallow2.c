begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the __VA_ARGS__ comma swallowing extensions of various compiler dialects.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s | FileCheck -check-prefix=GCC -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -std=c99 %s | FileCheck -check-prefix=C99 -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -std=c11 %s | FileCheck -check-prefix=C99 -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -x c++ %s | FileCheck -check-prefix=GCC -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -std=gnu99 %s | FileCheck -check-prefix=GCC -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -fms-compatibility %s | FileCheck -check-prefix=MS -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -DNAMED %s | FileCheck -check-prefix=GCC -strict-whitespace %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -std=c99 -DNAMED %s | FileCheck -check-prefix=C99 -strict-whitespace %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED
end_ifndef

begin_define
define|#
directive|define
name|A
parameter_list|(
modifier|...
parameter_list|)
value|[ __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
modifier|...
parameter_list|)
value|[ , __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
modifier|...
parameter_list|)
value|[ , ## __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|A
parameter_list|,
modifier|...
parameter_list|)
value|[ A , ## __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|E
parameter_list|(
name|A
parameter_list|,
modifier|...
parameter_list|)
value|[ __VA_ARGS__ ## A ]
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// These are the GCC named argument versions of the C99-style variadic macros.
end_comment

begin_comment
comment|// Note that __VA_ARGS__ *may* be used as the name, this is not prohibited!
end_comment

begin_define
define|#
directive|define
name|A
parameter_list|(
name|__VA_ARGS__
modifier|...
parameter_list|)
value|[ __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|__VA_ARGS__
modifier|...
parameter_list|)
value|[ , __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
name|__VA_ARGS__
modifier|...
parameter_list|)
value|[ , ## __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|A
parameter_list|,
name|__VA_ARGS__
modifier|...
parameter_list|)
value|[ A , ## __VA_ARGS__ ]
end_define

begin_define
define|#
directive|define
name|E
parameter_list|(
name|A
parameter_list|,
name|__VA_ARGS__
modifier|...
parameter_list|)
value|[ __VA_ARGS__ ## A ]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
literal|1
operator|:
name|A
argument_list|()
name|B
argument_list|()
name|C
argument_list|()
name|D
argument_list|()
name|E
argument_list|()
literal|2
operator|:
name|A
argument_list|(
argument|a
argument_list|)
name|B
argument_list|(
argument|a
argument_list|)
name|C
argument_list|(
argument|a
argument_list|)
name|D
argument_list|(
argument|a
argument_list|)
name|E
argument_list|(
name|a
argument_list|)
literal|3
operator|:
name|A
argument_list|(
argument_list|,)
name|B
argument_list|(
argument_list|,)
name|C
argument_list|(
argument_list|,)
name|D
argument_list|(
argument_list|,)
name|E
argument_list|(,)
literal|4
operator|:
name|A
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
name|B
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
name|C
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
name|D
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,
argument|c
argument_list|)
name|E
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
literal|5
operator|:
name|A
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,)
name|B
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,)
name|C
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,)
name|D
argument_list|(
argument|a
argument_list|,
argument|b
argument_list|,)
end_expr_stmt

begin_comment
comment|// The GCC ", ## __VA_ARGS__" extension swallows the comma when followed by
end_comment

begin_comment
comment|// empty __VA_ARGS__.  This extension does not apply in -std=c99 mode, but
end_comment

begin_comment
comment|// does apply in C++.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GCC: 1: [ ] [ , ] [ ] [ ] [ ]
end_comment

begin_comment
comment|// GCC: 2: [ a ] [ , a ] [ ,a ] [ a ] [ a ]
end_comment

begin_comment
comment|// GCC: 3: [ , ] [ , , ] [ ,, ] [ , ] [ ]
end_comment

begin_comment
comment|// GCC: 4: [ a,b,c ] [ , a,b,c ] [ ,a,b,c ] [ a ,b,c ] [ b,ca ]
end_comment

begin_comment
comment|// GCC: 5: [ a,b, ] [ , a,b, ] [ ,a,b, ] [ a ,b, ]
end_comment

begin_comment
comment|// Under C99 standard mode, the GCC ", ## __VA_ARGS__" extension *does not*
end_comment

begin_comment
comment|// swallow the comma when followed by empty __VA_ARGS__.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// C99: 1: [ ] [ , ] [ , ] [ ] [ ]
end_comment

begin_comment
comment|// C99: 2: [ a ] [ , a ] [ ,a ] [ a ] [ a ]
end_comment

begin_comment
comment|// C99: 3: [ , ] [ , , ] [ ,, ] [ , ] [ ]
end_comment

begin_comment
comment|// C99: 4: [ a,b,c ] [ , a,b,c ] [ ,a,b,c ] [ a ,b,c ] [ b,ca ]
end_comment

begin_comment
comment|// C99: 5: [ a,b, ] [ , a,b, ] [ ,a,b, ] [ a ,b, ]
end_comment

begin_comment
comment|// Microsoft's extension is on ", __VA_ARGS__" (without explicit ##) where
end_comment

begin_comment
comment|// the comma is swallowed when followed by empty __VA_ARGS__.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MS: 1: [ ] [ ] [ ] [ ] [ ]
end_comment

begin_comment
comment|// MS: 2: [ a ] [ , a ] [ ,a ] [ a ] [ a ]
end_comment

begin_comment
comment|// MS: 3: [ , ] [ , , ] [ ,, ] [ , ] [ ]
end_comment

begin_comment
comment|// MS: 4: [ a,b,c ] [ , a,b,c ] [ ,a,b,c ] [ a ,b,c ] [ b,ca ]
end_comment

begin_comment
comment|// MS: 5: [ a,b, ] [ , a,b, ] [ ,a,b, ] [ a ,b, ]
end_comment

begin_comment
comment|// FIXME: Item 3(d) in MS output should be [ ] not [ , ]
end_comment

end_unit

