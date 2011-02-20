begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 -mkernel -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN grep "-disable-red-zone" %t
end_comment

begin_comment
comment|// RUN grep "-fapple-kext" %t
end_comment

begin_comment
comment|// RUN grep "-fno-builtin" %t
end_comment

begin_comment
comment|// RUN grep "-fno-rtti" %t
end_comment

begin_comment
comment|// RUN grep "-fno-common" %t
end_comment

end_unit

