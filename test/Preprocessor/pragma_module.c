begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: echo 'module foo { module a {} module b {} } module bar {} module if {}'> %t/module.map
end_comment

begin_comment
comment|// RUN: %clang -cc1 -fmodules -fmodule-name=if -x c %t/module.map -emit-module -o %t/if.pcm
end_comment

begin_comment
comment|// RUN: %clang -cc1 -E -fmodules %s -fmodule-file=%t/if.pcm -verify -fmodule-name=foo -fmodule-map-file=%t/module.map
end_comment

begin_comment
comment|// RUN: %clang -cc1 -E -fmodules %s -fmodule-file=%t/if.pcm -verify -fmodule-name=foo -fmodule-map-file=%t/module.map -fmodules-local-submodule-visibility -DLOCAL_VIS
end_comment

begin_comment
comment|// Just checking the syntax here; the semantics are tested elsewhere.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
end_pragma

begin_comment
comment|// expected-error {{expected module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|!
end_pragma

begin_comment
comment|// expected-error {{expected module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|if
end_pragma

begin_comment
comment|// ok
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|?
name|bar
end_pragma

begin_comment
comment|// expected-warning {{extra tokens at end of #pragma}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|.
end_pragma

begin_comment
comment|// expected-error {{expected identifier after '.' in module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|.
name|bar
name|.
name|baz
name|.
name|quux
end_pragma

begin_comment
comment|// expected-error {{no submodule named 'bar' in module 'foo'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|!
end_pragma

begin_comment
comment|// expected-error {{expected module name}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|foo
name|.
name|a
name|blah
end_pragma

begin_comment
comment|// expected-warning {{extra tokens}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|foo
name|.
name|a
end_pragma

begin_comment
comment|// nesting is OK
end_comment

begin_define
define|#
directive|define
name|X
value|1
end_define

begin_comment
comment|// expected-note 0-1{{previous}}
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X
end_ifndef

begin_error
error|#
directive|error
error|X should be defined here
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|end
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|X
end_ifndef

begin_error
error|#
directive|error
error|X should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|end
name|foo
name|.
name|a
end_pragma

begin_comment
comment|// expected-warning {{extra tokens}}
end_comment

begin_comment
comment|// #pragma clang module begin/end also import the module into the enclosing context
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|X
end_ifndef

begin_error
error|#
directive|error
error|X should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|foo
name|.
name|b
end_pragma

begin_if
if|#
directive|if
name|defined
argument_list|(
name|X
argument_list|)
operator|&&
name|defined
argument_list|(
name|LOCAL_VIS
argument_list|)
end_if

begin_error
error|#
directive|error
error|under -fmodules-local-submodule-visibility, X should not be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|X
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCAL_VIS
argument_list|)
end_if

begin_error
error|#
directive|error
error|without -fmodules-local-submodule-visibility, X should still be defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|import
name|foo
name|.
name|a
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|X
end_ifndef

begin_error
error|#
directive|error
error|X should be defined here
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|end
end_pragma

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|end
end_pragma

begin_comment
comment|// expected-error {{no matching '#pragma clang module begin'}}
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|module
name|begin
name|foo
name|.
name|a
end_pragma

begin_comment
comment|// expected-error {{no matching '#pragma clang module end'}}
end_comment

end_unit

