begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PROTOCOLS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PROTOCOLS_H__
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_X86_32
value|"x86_32-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_X86_64
value|"x86_64-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_IA64
value|"ia64-abi"
end_define

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_POWERPC64
value|"powerpc64-abi"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_X86_32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_X86_64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_IA64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|XEN_IO_PROTO_ABI_NATIVE
value|XEN_IO_PROTO_ABI_POWERPC64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|arch fixup needed here
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

