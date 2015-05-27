begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu zEC12 -triple s390x-ibm-linux -Wall -Wno-unused -Werror -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu zEC12 -triple s390x-ibm-linux -Wall -Wno-unused -Werror -emit-llvm -x c++ %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<htmintrin.h>
end_include

begin_decl_stmt
name|int
name|global
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|g
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|__htm_tdb
name|global_tdb
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_htm1
parameter_list|(
name|struct
name|__htm_tdb
modifier|*
name|tdb
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
modifier|*
name|mem
parameter_list|,
name|uint64_t
modifier|*
name|mem64
parameter_list|)
block|{
comment|// CHECK-LABEL: test_htm1
name|__builtin_tbegin
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* null, i32 65292)
name|__builtin_tbegin
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x12345678
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* inttoptr (i64 305419896 to i8*), i32 65292)
name|__builtin_tbegin
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* %{{.*}}, i32 65292)
name|__builtin_tbegin
argument_list|(
operator|&
name|global_tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* getelementptr inbounds (%struct.__htm_tdb, %struct.__htm_tdb* @global_tdb, i32 0, i32 0), i32 65292)
name|__builtin_tbegin_nofloat
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* null, i32 65292)
name|__builtin_tbegin_nofloat
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x12345678
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* inttoptr (i64 305419896 to i8*), i32 65292)
name|__builtin_tbegin_nofloat
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* %{{.*}}, i32 65292)
name|__builtin_tbegin_nofloat
argument_list|(
operator|&
name|global_tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* getelementptr inbounds (%struct.__htm_tdb, %struct.__htm_tdb* @global_tdb, i32 0, i32 0), i32 65292)
name|__builtin_tbegin_retry
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* null, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x12345678
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry
argument_list|(
name|tdb
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry
argument_list|(
operator|&
name|global_tdb
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry_nofloat
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* null, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry_nofloat
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0x12345678
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry_nofloat
argument_list|(
name|tdb
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbegin_retry_nofloat
argument_list|(
operator|&
name|global_tdb
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* %{{.*}}, i32 65292)
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tbeginc
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tbeginc(i8* null, i32 65288)
name|__builtin_tabort
argument_list|(
literal|256
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tabort(i64 256)
name|__builtin_tabort
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tabort(i64 -1)
name|__builtin_tabort
argument_list|(
name|reg
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tabort(i64 %{{.*}})
name|__builtin_tend
argument_list|()
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tend()
name|int
name|n
init|=
name|__builtin_tx_nesting_depth
argument_list|()
decl_stmt|;
comment|// CHECK: call i32 @llvm.s390.etnd()
name|__builtin_non_tx_store
argument_list|(
name|mem64
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 0, i64* %{{.*}})
specifier|const
name|uint64_t
name|val_var
init|=
literal|0x1122334455667788
decl_stmt|;
name|__builtin_non_tx_store
argument_list|(
name|mem64
argument_list|,
name|val_var
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 1234605616436508552, i64* %{{.*}})
name|__builtin_non_tx_store
argument_list|(
name|mem64
argument_list|,
operator|(
name|uint64_t
operator|)
name|reg
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* %{{.*}})
name|__builtin_non_tx_store
argument_list|(
name|mem64
argument_list|,
name|g
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* %{{.*}})
name|__builtin_non_tx_store
argument_list|(
operator|(
name|uint64_t
operator|*
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 0, i64* null)
name|__builtin_non_tx_store
argument_list|(
operator|(
name|uint64_t
operator|*
operator|)
literal|0x12345678
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 0, i64* inttoptr (i64 305419896 to i64*))
name|__builtin_non_tx_store
argument_list|(
operator|&
name|g
argument_list|,
literal|23
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 23, i64* @g)
name|__builtin_non_tx_store
argument_list|(
operator|&
name|g
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* @g)
name|__builtin_non_tx_store
argument_list|(
operator|&
name|g
argument_list|,
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* @g)
name|__builtin_non_tx_store
argument_list|(
operator|&
name|g
argument_list|,
name|global
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* @g)
name|__builtin_tx_assist
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 0)
name|__builtin_tx_assist
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 1)
name|__builtin_tx_assist
argument_list|(
name|reg
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tx_assist
argument_list|(
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
name|__builtin_tx_assist
argument_list|(
name|global
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ppa.txassist(i32 %{{.*}})
block|}
end_function

begin_include
include|#
directive|include
file|<htmxlintrin.h>
end_include

begin_function
name|void
name|test_htmxl1
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_htmxl1
name|struct
name|__htm_tdb
name|tdb_struct
decl_stmt|;
name|void
modifier|*
specifier|const
name|tdb
init|=
operator|&
name|tdb_struct
decl_stmt|;
name|long
name|result
decl_stmt|;
name|unsigned
name|char
name|code
decl_stmt|;
name|result
operator|=
name|__TM_simple_begin
argument_list|()
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* null, i32 65292)
name|result
operator|=
name|__TM_begin
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tbegin.nofloat(i8* %{{.*}}, i32 65292)
name|result
operator|=
name|__TM_end
argument_list|()
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.tend()
name|__TM_abort
argument_list|()
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tabort(i64 256)
name|__TM_named_abort
argument_list|(
literal|42
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.tabort(i64 %{{.*}})
name|__TM_non_transactional_store
argument_list|(
operator|&
name|g
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.ntstg(i64 %{{.*}}, i64* %{{.*}})
name|result
operator|=
name|__TM_nesting_depth
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
comment|// CHECK: call i32 @llvm.s390.etnd()
name|result
operator|=
name|__TM_is_user_abort
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_named_user_abort
argument_list|(
name|tdb
argument_list|,
operator|&
name|code
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_illegal
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_footprint_exceeded
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_nested_too_deep
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_conflict
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_is_failure_persistent
argument_list|(
name|result
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_failure_address
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
name|result
operator|=
name|__TM_failure_code
argument_list|(
name|tdb
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

