begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env MACOSX_DEPLOYMENT_TARGET=10.1 %clang -ccc-host-triple i386-apple-darwin9 -E %s
end_comment

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

end_unit

