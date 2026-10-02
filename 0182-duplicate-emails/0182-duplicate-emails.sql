SELECT email
 FROM Person
group by email
having count(*)>1
