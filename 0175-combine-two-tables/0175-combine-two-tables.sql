SELECT firstName,lastName,city ,state
FROM person
left join address
on person.personId=Address.personId