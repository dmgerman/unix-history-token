begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.1 \
end_comment

begin_comment
comment|// RUN:   %clang -ccc-host-triple i386-apple-darwin9 -DTEST0 -E %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST0
end_ifdef

begin_if
if|#
directive|if
name|__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
operator|!=
literal|1010
end_if

begin_error
error|#
directive|error
error|Invalid version
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: env IPHONEOS_DEPLOYMENT_TARGET=2.0 \
end_comment

begin_comment
comment|// RUN:   %clang -ccc-host-triple i386-apple-darwin9 -DTEST1 -E %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST1
end_ifdef

begin_if
if|#
directive|if
name|__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
operator|!=
literal|20000
end_if

begin_error
error|#
directive|error
error|Invalid version
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: env IPHONEOS_DEPLOYMENT_TARGET=2.3.1 \
end_comment

begin_comment
comment|// RUN:   %clang -ccc-host-triple i386-apple-darwin9 -DTEST2 -E %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TEST2
end_ifdef

begin_if
if|#
directive|if
name|__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
operator|!=
literal|20301
end_if

begin_error
error|#
directive|error
error|Invalid version
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

