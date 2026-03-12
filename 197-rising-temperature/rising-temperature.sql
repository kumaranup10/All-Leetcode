# Write your MySQL query statement below
select w.id from Weather w join Weather d where 
datediff(w.recordDate,d.recordDate)=1
and 
w.temperature>d.temperature;