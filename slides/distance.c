/*****************************************************************************
**
*F FuncDistancePerms( <perm1>, <perm2> )
**
** 'DistancePerms' returns the number of points moved by <perm1>/<perm2>
**
*/

Obj FuncDistancePerms( Obj self, Obj p1, Obj p2)
{
UInt dist = 0;
if (TNUM_OBJ(p1) == T_PERM2 && TNUM_OBJ(p2) == T_PERM2) {
UInt2 *pt1 = ADDR_PERM2(p1);
UInt2 *pt2 = ADDR_PERM2(p2);
UInt l1 = DEG_PERM2(p1);
UInt l2 = DEG_PERM2(p2);
UInt lmin = (l1 < l2) ? l1 : l2;
UInt i;
for (i = 0; i < lmin; i++)
if (pt1[i] != pt2[i])
    dist++;
for (; i < l1; i++)
if (pt1[i] != i)
    dist++;
for (; i < l2; i++)
if (pt2[i] != i)
    dist++;
} else {
if (TNUM_OBJ(p1) == T_PERM2 && TNUM_OBJ(p2) == T_PERM4) {
Obj temp = p1;
p1 = p2;
p2 = temp;
}
if (TNUM_OBJ(p1) == T_PERM4 && TNUM_OBJ(p2) == T_PERM2) {
UInt4 *pt1 = ADDR_PERM4(p1);
UInt2 *pt2 = ADDR_PERM2(p2);
UInt l1 = DEG_PERM4(p1);
UInt l2 = DEG_PERM2(p2);
UInt lmin = (l1 < l2) ? l1 : l2;
UInt i;
for (i = 0; i < lmin; i++)
    if (pt1[i] != pt2[i])
     dist++;
for (; i < l1; i++)
    if (pt1[i] != i)
     dist++;
for (; i < l2; i++)
    if (pt2[i] != i)
     dist++;
} else {
UInt4 *pt1 = ADDR_PERM4(p1);
UInt4 *pt2 = ADDR_PERM4(p2);
UInt l1 = DEG_PERM4(p1);
UInt l2 = DEG_PERM4(p2);
UInt lmin = (l1 < l2) ? l1 : l2;
UInt i;
for (i = 0; i < lmin; i++)
    if (pt1[i] != pt2[i])
     dist++;
for (; i < l1; i++)
    if (pt1[i] != i)
     dist++;
for (; i < l2; i++)
    if (pt2[i] != i)
     dist++;
}
}
return INTOBJ_INT(dist);
}