begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// CHECK: [[@LINE+1]]:12 | class/ObjC | Base | [[Base_USR:.*]] | {{.*}} | Decl | rel: 0
end_comment

begin_expr_stmt
unit|@
name|interface
name|Base
expr|@
name|end
comment|// CHECK: [[@LINE+1]]:11 | protocol/ObjC | Prot1 | [[Prot1_USR:.*]] | {{.*}} | Decl | rel: 0
expr|@
name|protocol
name|Prot1
expr|@
name|end
comment|// CHECK: [[@LINE+3]]:11 | protocol/ObjC | Prot2 | [[Prot2_USR:.*]] | {{.*}} | Decl | rel: 0
comment|// CHECK: [[@LINE+2]]:17 | protocol/ObjC | Prot1 | [[Prot1_USR]] | {{.*}} | Ref,RelBase,RelCont | rel: 1
comment|// CHECK-NEXT: RelBase,RelCont | Prot2 | [[Prot2_USR]]
expr|@
name|protocol
name|Prot2
operator|<
name|Prot1
operator|>
expr|@
name|end
comment|// CHECK: [[@LINE+7]]:12 | class/ObjC | Sub | [[Sub_USR:.*]] | {{.*}} | Decl | rel: 0
comment|// CHECK: [[@LINE+6]]:18 | class/ObjC | Base | [[Base_USR]] | {{.*}} | Ref,RelBase,RelCont | rel: 1
comment|// CHECK-NEXT: RelBase,RelCont | Sub | [[Sub_USR]]
comment|// CHECK: [[@LINE+4]]:23 | protocol/ObjC | Prot2 | [[Prot2_USR]] | {{.*}} | Ref,RelBase,RelCont | rel: 1
comment|// CHECK-NEXT: RelBase,RelCont | Sub | [[Sub_USR]]
comment|// CHECK: [[@LINE+2]]:30 | protocol/ObjC | Prot1 | [[Prot1_USR]] | {{.*}} | Ref,RelBase,RelCont | rel: 1
comment|// CHECK-NEXT: RelBase,RelCont | Sub | [[Sub_USR]]
expr|@
name|interface
name|Sub
operator|:
name|Base
operator|<
name|Prot2
operator|,
name|Prot1
operator|>
comment|// CHECK-NOT: [[@LINE+1]]:3 | class/ObjC | Sub |
operator|-
operator|(
name|Sub
operator|*
operator|)
name|getit
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|@
name|end
comment|// CHECK: [[@LINE+1]]:7 | class/C++ | Cls | [[Cls_USR:.*]] | {{.*}} | Def | rel: 0
name|class
name|Cls
block|{}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: [[@LINE+3]]:7 | class/C++ | SubCls1 | [[SubCls1_USR:.*]] | {{.*}} | Def | rel: 0
end_comment

begin_comment
comment|// CHECK: [[@LINE+2]]:24 | class/C++ | Cls | [[Cls_USR]] | {{.*}} | Ref,RelBase,RelCont | rel: 1
end_comment

begin_comment
comment|// CHECK-NEXT: RelBase,RelCont | SubCls1 | [[SubCls1_USR]]
end_comment

begin_decl_stmt
name|class
name|SubCls1
range|:
name|public
name|Cls
block|{
comment|// CHECK-NOT: [[@LINE+1]]:3 | class/C++ | SubCls1 |
name|SubCls1
operator|*
name|f
block|; }
decl_stmt|;
end_decl_stmt

end_unit

