begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test conversions between complex integer types and standard integer
end_comment

begin_comment
comment|// types.  Tests binary operator conversion and assignment conversion
end_comment

begin_comment
comment|// with widening, narrowing, and equal-size operands.  Signed and unsigned
end_comment

begin_comment
comment|// variations.  Attempts to work for all targets.  Assumptions:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  * "char" and "long long" are of different lengths (CHSIZE and LLSIZE).
end_comment

begin_comment
comment|//  * Arithmetic is not performed directly on "char" type.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|signed
name|char
name|sc
parameter_list|,
name|unsigned
name|char
name|uc
parameter_list|,
name|signed
name|long
name|long
name|sll
parameter_list|,
name|unsigned
name|long
name|long
name|ull
parameter_list|,
specifier|_Complex
name|signed
name|char
name|csc
parameter_list|,
specifier|_Complex
name|unsigned
name|char
name|cuc
parameter_list|,
specifier|_Complex
name|signed
name|long
name|long
name|csll
parameter_list|,
specifier|_Complex
name|unsigned
name|long
name|long
name|cull
parameter_list|)
block|{
name|signed
name|char
name|sc1
decl_stmt|;
name|unsigned
name|char
name|uc1
decl_stmt|;
name|signed
name|long
name|long
name|sll1
decl_stmt|;
name|unsigned
name|long
name|long
name|ull1
decl_stmt|;
specifier|_Complex
name|signed
name|char
name|csc1
decl_stmt|;
specifier|_Complex
name|unsigned
name|char
name|cuc1
decl_stmt|;
specifier|_Complex
name|signed
name|long
name|long
name|csll1
decl_stmt|;
specifier|_Complex
name|unsigned
name|long
name|long
name|cull1
decl_stmt|;
comment|// CHECK-LABEL: define void @foo(
comment|// Match the prototype to pick up the size of sc and sll.
comment|// CHECK: i[[CHSIZE:[0-9]+]]{{[^,]*}},
comment|// CHECK: i[[CHSIZE]]{{[^,]*}},
comment|// CHECK: i[[LLSIZE:[0-9]+]]
comment|// Match against the allocas to pick up the alignments.
comment|// CHECK: alloca i[[CHSIZE]], align [[CHALIGN:[0-9]+]]
comment|// CHECK: alloca i[[LLSIZE]], align [[LLALIGN:[0-9]+]]
name|sc1
operator|=
name|csc
expr_stmt|;
comment|// CHECK: %[[VAR1:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CSC:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR2:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR1]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR2]], i[[CHSIZE]]* %[[SC1:[A-Za-z0-9.]+]], align [[CHALIGN]]
name|sc1
operator|=
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR3:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CUC:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR4:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR3]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR4]], i[[CHSIZE]]* %[[SC1]], align [[CHALIGN]]
name|sc1
operator|=
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR5:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]]  }* %[[CSLL:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR6:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR5]]
comment|// CHECK-NEXT: %[[VAR7:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR6]] to i[[CHSIZE]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR7]], i[[CHSIZE]]* %[[SC1]], align [[CHALIGN]]
name|sc1
operator|=
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR8:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]]  }* %[[CULL:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR9:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR8]]
comment|// CHECK-NEXT: %[[VAR10:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR9]] to i[[CHSIZE]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR10]], i[[CHSIZE]]* %[[SC1]], align [[CHALIGN]]
name|uc1
operator|=
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR11:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR12:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR11]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR12]], i[[CHSIZE]]* %[[UC1:[A-Za-z0-9.]+]], align [[CHALIGN]]
name|uc1
operator|=
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR13:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR14:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR13]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR14]], i[[CHSIZE]]* %[[UC1]], align [[CHALIGN]]
name|uc1
operator|=
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR15:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]]  }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR16:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR15]]
comment|// CHECK-NEXT: %[[VAR17:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR16]] to i[[CHSIZE]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR17]], i[[CHSIZE]]* %[[UC1]], align [[CHALIGN]]
name|uc1
operator|=
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR18:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]]  }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR19:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR18]]
comment|// CHECK-NEXT: %[[VAR20:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR19]] to i[[CHSIZE]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR20]], i[[CHSIZE]]* %[[UC1]], align [[CHALIGN]]
name|sll1
operator|=
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR21:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR22:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR21]]
comment|// CHECK-NEXT: %[[VAR23:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR22]] to i[[LLSIZE]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR23]], i[[LLSIZE]]* %[[SLL1:[A-Za-z0-9]+]], align [[LLALIGN]]
name|sll1
operator|=
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR24:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]]  }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR25:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR24]]
comment|// CHECK-NEXT: %[[VAR26:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR25]] to i[[LLSIZE]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR26]], i[[LLSIZE]]* %[[SLL1]], align [[LLALIGN]]
name|sll1
operator|=
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR27:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR28:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR27]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR28]], i[[LLSIZE]]* %[[SLL1]], align [[LLALIGN]]
name|sll1
operator|=
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR29:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR30:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR29]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR30]], i[[LLSIZE]]* %[[SLL1]], align [[LLALIGN]]
name|ull1
operator|=
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR31:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR32:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR31]]
comment|// CHECK-NEXT: %[[VAR33:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR32]] to i[[LLSIZE]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR33]], i[[LLSIZE]]* %[[ULL1:[A-Za-z0-9]+]], align [[LLALIGN]]
name|ull1
operator|=
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR34:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR35:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR34]]
comment|// CHECK-NEXT: %[[VAR36:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR35]] to i[[LLSIZE]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR36]], i[[LLSIZE]]* %[[ULL1]], align [[LLALIGN]]
name|ull1
operator|=
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR37:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR38:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR37]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR38]], i[[LLSIZE]]* %[[ULL1]], align [[LLALIGN]]
name|ull1
operator|=
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR39:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR40:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR39]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR40]], i[[LLSIZE]]* %[[ULL1]], align [[LLALIGN]]
name|csc1
operator|=
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR41:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR:[A-Za-z0-9.]+]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR42:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR43:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR41]], i[[CHSIZE]]* %[[VAR42]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR43]]
name|csc1
operator|=
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR44:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR:[A-Za-z0-9.]+]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR45:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR46:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR44]], i[[CHSIZE]]* %[[VAR45]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR46]]
name|csc1
operator|=
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR47:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR:[A-Za-z0-9.]+]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR48:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR47]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR49:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR50:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR48]], i[[CHSIZE]]* %[[VAR49]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR50]]
name|csc1
operator|=
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR51:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR:[A-Za-z0-9.]+]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR52:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR51]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR53:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR54:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR52]], i[[CHSIZE]]* %[[VAR53]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR54]]
name|cuc1
operator|=
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR55:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR56:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR57:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR55]], i[[CHSIZE]]* %[[VAR56]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR57]]
name|cuc1
operator|=
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR58:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR59:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR60:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR58]], i[[CHSIZE]]* %[[VAR59]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR60]]
name|cuc1
operator|=
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR61:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR62:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR61]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR63:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR64:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR62]], i[[CHSIZE]]* %[[VAR63]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR64]]
name|cuc1
operator|=
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR65:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR66:[A-Za-z0-9.]+]] = trunc i[[LLSIZE]] %[[VAR65]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR67:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR68:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR66]], i[[CHSIZE]]* %[[VAR67]]
comment|// CHECK-NEXT: store i[[CHSIZE]] 0, i[[CHSIZE]]* %[[VAR68]]
name|csll1
operator|=
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR69:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR70:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR69]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR71:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR72:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR70]], i[[LLSIZE]]* %[[VAR71]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR72]]
name|csll1
operator|=
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR73:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR74:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR73]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR75:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR76:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR74]], i[[LLSIZE]]* %[[VAR75]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR76]]
name|csll1
operator|=
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR77:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR78:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR79:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR77]], i[[LLSIZE]]* %[[VAR78]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR79]]
name|csll1
operator|=
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR77:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR78:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR79:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR77]], i[[LLSIZE]]* %[[VAR78]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR79]]
name|cull1
operator|=
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR80:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR81:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR80]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR82:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1:[A-Za-z0-9.]+]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR83:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR81]], i[[LLSIZE]]* %[[VAR82]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR83]]
name|cull1
operator|=
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR84:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR85:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR84]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR86:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR87:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR85]], i[[LLSIZE]]* %[[VAR86]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR87]]
name|cull1
operator|=
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR88:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR89:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR90:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR88]], i[[LLSIZE]]* %[[VAR89]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR90]]
name|cull1
operator|=
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR91:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR92:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR93:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR91]], i[[LLSIZE]]* %[[VAR92]]
comment|// CHECK-NEXT: store i[[LLSIZE]] 0, i[[LLSIZE]]* %[[VAR93]]
name|csc1
operator|=
name|sc
operator|+
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR94:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR95:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR94]] to i[[ARSIZE:[0-9]+]]
comment|// CHECK-NEXT: %[[VAR96:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR97:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR96]]
comment|// CHECK-NEXT: %[[VAR98:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR99:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR98]]
comment|// CHECK-NEXT: %[[VAR100:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR97]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR101:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR99]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR102:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR95]], %[[VAR100]]
comment|// CHECK-NEXT: %[[VAR103:[A-Za-z0-9.]+]] = add i[[ARSIZE]] 0, %[[VAR101]]
comment|// CHECK-NEXT: %[[VAR104:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR102]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR105:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR103]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR106:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR107:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR104]], i[[CHSIZE]]* %[[VAR106]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR105]], i[[CHSIZE]]* %[[VAR107]]
name|cuc1
operator|=
name|sc
operator|+
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR108:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR109:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR108]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR110:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR111:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR110]]
comment|// CHECK-NEXT: %[[VAR112:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR113:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR112]]
comment|// CHECK-NEXT: %[[VAR114:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR111]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR115:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR113]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR116:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR109]], %[[VAR114]]
comment|// CHECK-NEXT: %[[VAR117:[A-Za-z0-9.]+]] = add i[[ARSIZE]] 0, %[[VAR115]]
comment|// CHECK-NEXT: %[[VAR118:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR116]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR119:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR117]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR120:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR121:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR118]], i[[CHSIZE]]* %[[VAR120]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR119]], i[[CHSIZE]]* %[[VAR121]]
name|csll1
operator|=
name|sc
operator|+
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR122:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR123:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR122]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR124:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR125:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR124]]
comment|// CHECK-NEXT: %[[VAR126:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR127:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR126]]
comment|// CHECK-NEXT: %[[VAR128:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR123]], %[[VAR125]]
comment|// CHECK-NEXT: %[[VAR129:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR127]]
comment|// CHECK-NEXT: %[[VAR130:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR131:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR128]], i[[LLSIZE]]* %[[VAR130]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR129]], i[[LLSIZE]]* %[[VAR131]]
name|cull1
operator|=
name|sc
operator|+
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR132:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR133:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR132]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR134:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR135:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR134]]
comment|// CHECK-NEXT: %[[VAR136:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR137:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR136]]
comment|// CHECK-NEXT: %[[VAR138:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR133]], %[[VAR135]]
comment|// CHECK-NEXT: %[[VAR139:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR137]]
comment|// CHECK-NEXT: %[[VAR140:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR141:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR138]], i[[LLSIZE]]* %[[VAR140]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR139]], i[[LLSIZE]]* %[[VAR141]]
name|csc1
operator|=
name|uc
operator|+
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR142:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR143:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR142]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR144:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR145:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR144]]
comment|// CHECK-NEXT: %[[VAR146:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR147:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR146]]
comment|// CHECK-NEXT: %[[VAR148:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR145]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR149:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR147]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR150:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR143]], %[[VAR148]]
comment|// CHECK-NEXT: %[[VAR151:[A-Za-z0-9.]+]] = add i[[ARSIZE]] 0, %[[VAR149]]
comment|// CHECK-NEXT: %[[VAR152:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR150]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR153:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR151]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR154:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR155:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR152]], i[[CHSIZE]]* %[[VAR154]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR153]], i[[CHSIZE]]* %[[VAR155]]
name|cuc1
operator|=
name|uc
operator|+
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR156:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR157:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR156]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR158:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR159:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR158]]
comment|// CHECK-NEXT: %[[VAR160:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR161:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR160]]
comment|// CHECK-NEXT: %[[VAR162:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR159]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR163:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR161]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR164:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR157]], %[[VAR162]]
comment|// CHECK-NEXT: %[[VAR165:[A-Za-z0-9.]+]] = add i[[ARSIZE]] 0, %[[VAR163]]
comment|// CHECK-NEXT: %[[VAR166:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR164]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR167:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR165]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR168:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR169:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR166]], i[[CHSIZE]]* %[[VAR168]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR167]], i[[CHSIZE]]* %[[VAR169]]
name|csll1
operator|=
name|uc
operator|+
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR170:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR171:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR170]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR172:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR173:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR172]]
comment|// CHECK-NEXT: %[[VAR174:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR175:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR174]]
comment|// CHECK-NEXT: %[[VAR176:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR171]], %[[VAR173]]
comment|// CHECK-NEXT: %[[VAR177:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR175]]
comment|// CHECK-NEXT: %[[VAR178:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR179:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR176]], i[[LLSIZE]]* %[[VAR178]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR177]], i[[LLSIZE]]* %[[VAR179]]
name|cull1
operator|=
name|uc
operator|+
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR180:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR181:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR180]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR182:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR183:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR182]]
comment|// CHECK-NEXT: %[[VAR184:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR185:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR184]]
comment|// CHECK-NEXT: %[[VAR186:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR181]], %[[VAR183]]
comment|// CHECK-NEXT: %[[VAR187:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR185]]
comment|// CHECK-NEXT: %[[VAR188:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR189:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR186]], i[[LLSIZE]]* %[[VAR188]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR187]], i[[LLSIZE]]* %[[VAR189]]
name|csll1
operator|=
name|sll
operator|+
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR190:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR191:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR192:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR191]]
comment|// CHECK-NEXT: %[[VAR193:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR194:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR193]]
comment|// CHECK-NEXT: %[[VAR195:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR192]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR196:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR194]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR197:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR190]], %[[VAR195]]
comment|// CHECK-NEXT: %[[VAR198:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR196]]
comment|// CHECK-NEXT: %[[VAR199:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR200:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR197]], i[[LLSIZE]]* %[[VAR199]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR198]], i[[LLSIZE]]* %[[VAR200]]
name|csll1
operator|=
name|sll
operator|+
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR201:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR202:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR203:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR202]]
comment|// CHECK-NEXT: %[[VAR204:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR205:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR204]]
comment|// CHECK-NEXT: %[[VAR206:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR203]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR207:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR205]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR208:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR201]], %[[VAR206]]
comment|// CHECK-NEXT: %[[VAR209:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR207]]
comment|// CHECK-NEXT: %[[VAR210:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR211:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR208]], i[[LLSIZE]]* %[[VAR210]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR209]], i[[LLSIZE]]* %[[VAR211]]
name|csll1
operator|=
name|sll
operator|+
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR212:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR213:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR214:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR213]]
comment|// CHECK-NEXT: %[[VAR215:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR216:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR215]]
comment|// CHECK-NEXT: %[[VAR217:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR212]], %[[VAR214]]
comment|// CHECK-NEXT: %[[VAR218:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR216]]
comment|// CHECK-NEXT: %[[VAR219:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR220:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR217]], i[[LLSIZE]]* %[[VAR219]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR218]], i[[LLSIZE]]* %[[VAR220]]
name|csll1
operator|=
name|sll
operator|+
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR221:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR222:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR223:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR222]]
comment|// CHECK-NEXT: %[[VAR224:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR225:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR224]]
comment|// CHECK-NEXT: %[[VAR226:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR221]], %[[VAR223]]
comment|// CHECK-NEXT: %[[VAR227:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR225]]
comment|// CHECK-NEXT: %[[VAR228:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR229:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR226]], i[[LLSIZE]]* %[[VAR228]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR227]], i[[LLSIZE]]* %[[VAR229]]
name|csll1
operator|=
name|ull
operator|+
name|csc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR230:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR231:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR232:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR231]]
comment|// CHECK-NEXT: %[[VAR233:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR234:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR233]]
comment|// CHECK-NEXT: %[[VAR235:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR232]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR236:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR234]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR237:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR230]], %[[VAR235]]
comment|// CHECK-NEXT: %[[VAR238:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR236]]
comment|// CHECK-NEXT: %[[VAR239:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR240:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR237]], i[[LLSIZE]]* %[[VAR239]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR238]], i[[LLSIZE]]* %[[VAR240]]
name|cull1
operator|=
name|ull
operator|+
name|cuc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR241:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR242:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR243:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR242]]
comment|// CHECK-NEXT: %[[VAR244:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR245:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR244]]
comment|// CHECK-NEXT: %[[VAR246:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR243]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR247:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR245]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR248:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR241]], %[[VAR246]]
comment|// CHECK-NEXT: %[[VAR249:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR247]]
comment|// CHECK-NEXT: %[[VAR250:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR251:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR248]], i[[LLSIZE]]* %[[VAR250]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR249]], i[[LLSIZE]]* %[[VAR251]]
name|csll1
operator|=
name|ull
operator|+
name|csll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR252:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR253:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR254:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR253]]
comment|// CHECK-NEXT: %[[VAR255:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR256:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR255]]
comment|// CHECK-NEXT: %[[VAR257:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR252]], %[[VAR254]]
comment|// CHECK-NEXT: %[[VAR258:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR256]]
comment|// CHECK-NEXT: %[[VAR259:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR260:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR257]], i[[LLSIZE]]* %[[VAR259]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR258]], i[[LLSIZE]]* %[[VAR260]]
name|cull1
operator|=
name|ull
operator|+
name|cull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR261:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR262:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR263:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR262]]
comment|// CHECK-NEXT: %[[VAR264:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR265:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR264]]
comment|// CHECK-NEXT: %[[VAR266:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR261]], %[[VAR263]]
comment|// CHECK-NEXT: %[[VAR267:[A-Za-z0-9.]+]] = add i[[LLSIZE]] 0, %[[VAR265]]
comment|// CHECK-NEXT: %[[VAR268:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR269:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR266]], i[[LLSIZE]]* %[[VAR268]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR267]], i[[LLSIZE]]* %[[VAR269]]
name|csc1
operator|=
name|csc
operator|+
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR270:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR271:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR270]]
comment|// CHECK-NEXT: %[[VAR272:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR273:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR272]]
comment|// CHECK-NEXT: %[[VAR274:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR271]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR275:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR273]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR276:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR277:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR276]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR278:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR274]], %[[VAR277]]
comment|// CHECK-NEXT: %[[VAR279:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR275]], 0
comment|// CHECK-NEXT: %[[VAR280:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR278]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR281:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR279]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR282:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR283:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR280]], i[[CHSIZE]]* %[[VAR282]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR281]], i[[CHSIZE]]* %[[VAR283]]
name|csc1
operator|=
name|csc
operator|+
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR284:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR285:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR284]]
comment|// CHECK-NEXT: %[[VAR286:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR287:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR286]]
comment|// CHECK-NEXT: %[[VAR288:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR285]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR289:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR287]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR290:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR291:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR290]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR292:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR288]], %[[VAR291]]
comment|// CHECK-NEXT: %[[VAR293:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR289]], 0
comment|// CHECK-NEXT: %[[VAR294:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR292]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR295:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR293]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR296:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR297:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR294]], i[[CHSIZE]]* %[[VAR296]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR295]], i[[CHSIZE]]* %[[VAR297]]
name|csll1
operator|=
name|csc
operator|+
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR298:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR299:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR298]]
comment|// CHECK-NEXT: %[[VAR300:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR301:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR300]]
comment|// CHECK-NEXT: %[[VAR302:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR299]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR303:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR301]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR304:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR305:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR302]], %[[VAR304]]
comment|// CHECK-NEXT: %[[VAR306:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR303]], 0
comment|// CHECK-NEXT: %[[VAR307:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR308:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR305]], i[[LLSIZE]]* %[[VAR307]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR306]], i[[LLSIZE]]* %[[VAR308]]
name|csll1
operator|=
name|csc
operator|+
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR309:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR310:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR309]]
comment|// CHECK-NEXT: %[[VAR311:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR312:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR311]]
comment|// CHECK-NEXT: %[[VAR313:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR310]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR314:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR312]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR315:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR316:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR313]], %[[VAR315]]
comment|// CHECK-NEXT: %[[VAR317:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR314]], 0
comment|// CHECK-NEXT: %[[VAR318:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR319:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR316]], i[[LLSIZE]]* %[[VAR318]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR317]], i[[LLSIZE]]* %[[VAR319]]
name|csc1
operator|=
name|cuc
operator|+
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR320:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR321:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR320]]
comment|// CHECK-NEXT: %[[VAR322:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR323:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR322]]
comment|// CHECK-NEXT: %[[VAR324:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR321]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR325:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR323]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR326:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR327:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR326]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR328:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR324]], %[[VAR327]]
comment|// CHECK-NEXT: %[[VAR329:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR325]], 0
comment|// CHECK-NEXT: %[[VAR330:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR328]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR331:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR329]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR332:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR333:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CSC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR330]], i[[CHSIZE]]* %[[VAR332]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR331]], i[[CHSIZE]]* %[[VAR333]]
name|cuc1
operator|=
name|cuc
operator|+
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR334:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR335:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR334]]
comment|// CHECK-NEXT: %[[VAR336:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR337:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR336]]
comment|// CHECK-NEXT: %[[VAR338:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR335]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR339:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR337]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR340:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR341:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR340]] to i[[ARSIZE]]
comment|// CHECK-NEXT: %[[VAR342:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR338]], %[[VAR341]]
comment|// CHECK-NEXT: %[[VAR343:[A-Za-z0-9.]+]] = add i[[ARSIZE]] %[[VAR339]], 0
comment|// CHECK-NEXT: %[[VAR344:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR342]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR345:[A-Za-z0-9.]+]] = trunc i[[ARSIZE]] %[[VAR343]] to i[[CHSIZE]]
comment|// CHECK-NEXT: %[[VAR346:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR347:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR344]], i[[CHSIZE]]* %[[VAR346]]
comment|// CHECK-NEXT: store i[[CHSIZE]] %[[VAR345]], i[[CHSIZE]]* %[[VAR347]]
name|csll1
operator|=
name|cuc
operator|+
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR348:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR349:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR348]]
comment|// CHECK-NEXT: %[[VAR350:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR351:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR350]]
comment|// CHECK-NEXT: %[[VAR352:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR349]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR353:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR351]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR354:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR355:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR352]], %[[VAR354]]
comment|// CHECK-NEXT: %[[VAR356:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR353]], 0
comment|// CHECK-NEXT: %[[VAR357:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR358:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR355]], i[[LLSIZE]]* %[[VAR357]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR356]], i[[LLSIZE]]* %[[VAR358]]
name|cull1
operator|=
name|cuc
operator|+
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR357:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR358:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR357]]
comment|// CHECK-NEXT: %[[VAR359:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[CHSIZE]], i[[CHSIZE]] }* %[[CUC]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR360:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[VAR359]]
comment|// CHECK-NEXT: %[[VAR361:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR358]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR362:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR360]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR363:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR364:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR361]], %[[VAR363]]
comment|// CHECK-NEXT: %[[VAR365:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR362]], 0
comment|// CHECK-NEXT: %[[VAR366:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR367:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR364]], i[[LLSIZE]]* %[[VAR366]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR365]], i[[LLSIZE]]* %[[VAR367]]
name|csll1
operator|=
name|csll
operator|+
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR368:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR369:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR368]]
comment|// CHECK-NEXT: %[[VAR370:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR371:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR370]]
comment|// CHECK-NEXT: %[[VAR372:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR373:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR372]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR374:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR369]], %[[VAR373]]
comment|// CHECK-NEXT: %[[VAR375:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR371]], 0
comment|// CHECK-NEXT: %[[VAR376:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR377:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR374]], i[[LLSIZE]]* %[[VAR376]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR375]], i[[LLSIZE]]* %[[VAR377]]
name|csll1
operator|=
name|csll
operator|+
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR378:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR379:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR378]]
comment|// CHECK-NEXT: %[[VAR380:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR381:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR380]]
comment|// CHECK-NEXT: %[[VAR382:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR383:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR382]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR384:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR379]], %[[VAR383]]
comment|// CHECK-NEXT: %[[VAR385:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR381]], 0
comment|// CHECK-NEXT: %[[VAR386:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR387:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR384]], i[[LLSIZE]]* %[[VAR386]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR385]], i[[LLSIZE]]* %[[VAR387]]
name|csll1
operator|=
name|csll
operator|+
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR388:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR389:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR388]]
comment|// CHECK-NEXT: %[[VAR390:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR391:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR390]]
comment|// CHECK-NEXT: %[[VAR392:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR393:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR389]], %[[VAR392]]
comment|// CHECK-NEXT: %[[VAR394:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR391]], 0
comment|// CHECK-NEXT: %[[VAR395:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR396:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR393]], i[[LLSIZE]]* %[[VAR395]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR394]], i[[LLSIZE]]* %[[VAR396]]
name|csll1
operator|=
name|csll
operator|+
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR397:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR398:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR397]]
comment|// CHECK-NEXT: %[[VAR399:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR400:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR399]]
comment|// CHECK-NEXT: %[[VAR401:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR402:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR398]], %[[VAR401]]
comment|// CHECK-NEXT: %[[VAR403:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR400]], 0
comment|// CHECK-NEXT: %[[VAR404:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR405:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR402]], i[[LLSIZE]]* %[[VAR404]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR403]], i[[LLSIZE]]* %[[VAR405]]
name|csll1
operator|=
name|cull
operator|+
name|sc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR406:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR407:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR406]]
comment|// CHECK-NEXT: %[[VAR408:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR409:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR408]]
comment|// CHECK-NEXT: %[[VAR410:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[SCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR411:[A-Za-z0-9.]+]] = sext i[[CHSIZE]] %[[VAR410]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR412:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR407]], %[[VAR411]]
comment|// CHECK-NEXT: %[[VAR413:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR409]], 0
comment|// CHECK-NEXT: %[[VAR414:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR415:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR412]], i[[LLSIZE]]* %[[VAR414]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR413]], i[[LLSIZE]]* %[[VAR415]]
name|cull1
operator|=
name|cull
operator|+
name|uc
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR416:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR417:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR416]]
comment|// CHECK-NEXT: %[[VAR418:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR419:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR418]]
comment|// CHECK-NEXT: %[[VAR420:[A-Za-z0-9.]+]] = load i[[CHSIZE]]* %[[UCADDR]], align [[CHALIGN]]
comment|// CHECK-NEXT: %[[VAR421:[A-Za-z0-9.]+]] = zext i[[CHSIZE]] %[[VAR420]] to i[[LLSIZE]]
comment|// CHECK-NEXT: %[[VAR422:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR417]], %[[VAR421]]
comment|// CHECK-NEXT: %[[VAR423:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR419]], 0
comment|// CHECK-NEXT: %[[VAR424:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR425:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR422]], i[[LLSIZE]]* %[[VAR424]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR423]], i[[LLSIZE]]* %[[VAR425]]
name|csll1
operator|=
name|cull
operator|+
name|sll
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR426:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR427:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR426]]
comment|// CHECK-NEXT: %[[VAR428:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR429:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR428]]
comment|// CHECK-NEXT: %[[VAR430:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[SLLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR431:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR427]], %[[VAR430]]
comment|// CHECK-NEXT: %[[VAR432:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR429]], 0
comment|// CHECK-NEXT: %[[VAR433:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR434:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CSLL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR431]], i[[LLSIZE]]* %[[VAR433]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR432]], i[[LLSIZE]]* %[[VAR434]]
name|cull1
operator|=
name|cull
operator|+
name|ull
expr_stmt|;
comment|// CHECK-NEXT: %[[VAR435:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR436:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR435]]
comment|// CHECK-NEXT: %[[VAR437:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: %[[VAR438:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[VAR437]]
comment|// CHECK-NEXT: %[[VAR439:[A-Za-z0-9.]+]] = load i[[LLSIZE]]* %[[ULLADDR]], align [[LLALIGN]]
comment|// CHECK-NEXT: %[[VAR440:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR436]], %[[VAR439]]
comment|// CHECK-NEXT: %[[VAR441:[A-Za-z0-9.]+]] = add i[[LLSIZE]] %[[VAR438]], 0
comment|// CHECK-NEXT: %[[VAR442:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 0
comment|// CHECK-NEXT: %[[VAR443:[A-Za-z0-9.]+]] = getelementptr inbounds { i[[LLSIZE]], i[[LLSIZE]] }* %[[CULL1]], i{{[0-9]+}} 0, i{{[0-9]+}} 1
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR440]], i[[LLSIZE]]* %[[VAR442]]
comment|// CHECK-NEXT: store i[[LLSIZE]] %[[VAR441]], i[[LLSIZE]]* %[[VAR443]]
block|}
end_function

end_unit

