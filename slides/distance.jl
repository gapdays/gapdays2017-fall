type perm{T <: Integer}
   d::Array{T, 1}
   deg::Int   
end
   

function perm_distance(p1::perm{T}, p2::perm{T}) where T <: Integer
   dist = 0
   i = 1
   while i <= min(p1.deg, p2.deg)
      if p1.d[i] != p2.d[i]
         dist += 1
      end
      i += 1
   end
   while i <= p1.deg
      if p1.d[i] != i
         dist += 1
      end
      i += 1
   end
   while i <= p2.deg
      if p2.d[i] != i
         dist += 1
      end
      i += 1
   end
   return dist
end

a = perm(Int8[1, 3, 2, 4], 3)
b = perm(Int8[3, 4, 1, 2], 4)

perm_distance(a, b)