begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -### -S -x c /dev/null -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fno-math-errno -fno-common -fno-pascal-strings -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings %s 2> %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fblocks"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"--fmath-errno=1"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fpascal-strings"' %t
end_comment

begin_comment
comment|// RUN: clang -### -S -x c /dev/null -fblocks -fbuiltin -fmath-errno -fcommon -fpascal-strings -fno-blocks -fno-builtin -fno-math-errno -fno-common -fno-pascal-strings -fno-show-source-location -fshort-wchar %s 2> %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fbuiltin=0"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fno-common"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"--fmath-errno=0"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fno-show-source-location"' %t
end_comment

begin_comment
comment|// RUN: grep -F '"-fshort-wchar"' %t
end_comment

end_unit

