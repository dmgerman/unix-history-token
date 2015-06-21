begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|////
end_comment

begin_comment
comment|//// Verify that valid options for the -mrecip flag are passed through and invalid options cause an error.
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|//// If there are no options, convert to 'all'.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip  2>&1 | FileCheck --check-prefix=RECIP0 %s
end_comment

begin_comment
comment|// RECIP0: "-mrecip=all"
end_comment

begin_comment
comment|//// Check options that cover all types.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=all  2>&1 | FileCheck --check-prefix=RECIP1 %s
end_comment

begin_comment
comment|// RECIP1: "-mrecip=all"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=default  2>&1 | FileCheck --check-prefix=RECIP2 %s
end_comment

begin_comment
comment|// RECIP2: "-mrecip=default"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=none  2>&1 | FileCheck --check-prefix=RECIP3 %s
end_comment

begin_comment
comment|// RECIP3: "-mrecip=none"
end_comment

begin_comment
comment|//// Check options that do not specify float or double.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=vec-sqrt  2>&1 | FileCheck --check-prefix=RECIP4 %s
end_comment

begin_comment
comment|// RECIP4: "-mrecip=vec-sqrt"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=!div,vec-div  2>&1 | FileCheck --check-prefix=RECIP5 %s
end_comment

begin_comment
comment|// RECIP5: "-mrecip=!div,vec-div"
end_comment

begin_comment
comment|//// Check individual option types.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=vec-sqrtd  2>&1 | FileCheck --check-prefix=RECIP6 %s
end_comment

begin_comment
comment|// RECIP6: "-mrecip=vec-sqrtd"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=!divf  2>&1 | FileCheck --check-prefix=RECIP7 %s
end_comment

begin_comment
comment|// RECIP7: "-mrecip=!divf"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=divf,sqrtd,vec-divd,vec-sqrtf  2>&1 | FileCheck --check-prefix=RECIP8 %s
end_comment

begin_comment
comment|// RECIP8: "-mrecip=divf,sqrtd,vec-divd,vec-sqrtf"
end_comment

begin_comment
comment|//// Check optional refinement step specifiers.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=all:1  2>&1 | FileCheck --check-prefix=RECIP9 %s
end_comment

begin_comment
comment|// RECIP9: "-mrecip=all:1"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=sqrtf:3  2>&1 | FileCheck --check-prefix=RECIP10 %s
end_comment

begin_comment
comment|// RECIP10: "-mrecip=sqrtf:3"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=div:5  2>&1 | FileCheck --check-prefix=RECIP11 %s
end_comment

begin_comment
comment|// RECIP11: "-mrecip=div:5"
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=divd:1,!sqrtf:2,vec-divf:9,vec-sqrtd:0  2>&1 | FileCheck --check-prefix=RECIP12 %s
end_comment

begin_comment
comment|// RECIP12: "-mrecip=divd:1,!sqrtf:2,vec-divf:9,vec-sqrtd:0"
end_comment

begin_comment
comment|//// Check invalid parameters.
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=bogus  2>&1 | FileCheck --check-prefix=RECIP13 %s
end_comment

begin_comment
comment|// RECIP13: error: unknown argument
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=divd:1,divd  2>&1 | FileCheck --check-prefix=RECIP14 %s
end_comment

begin_comment
comment|// RECIP14: error: invalid value
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=sqrt,sqrtf  2>&1 | FileCheck --check-prefix=RECIP15 %s
end_comment

begin_comment
comment|// RECIP15: error: invalid value
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=+default:10  2>&1 | FileCheck --check-prefix=RECIP16 %s
end_comment

begin_comment
comment|// RECIP16: error: invalid value
end_comment

begin_comment
comment|// RUN: %clang -### -S %s -mrecip=!vec-divd:  2>&1 | FileCheck --check-prefix=RECIP17 %s
end_comment

begin_comment
comment|// RECIP17: error: invalid value
end_comment

end_unit

