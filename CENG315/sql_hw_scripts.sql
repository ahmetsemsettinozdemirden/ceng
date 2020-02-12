
select r.id, r.name 
from restourant r
where r.university_id = (select id from university where name = 'iyte') 
and (select count(1) from product p where p.restourant_id = r.id and p.product_type = 'PIZZA') != 0
and (select avg(rating) from comments c where c.restourant_id = r.id group by c.restourant_id) > 4;

1.3 Queries
1. check customer credentials by using e-mail and password, using count() that matches any record in the table and return customer_id on customer table.
2. fetch customer details by using select and customer_id on customer table.
3. fetch all comments of a customer by using select and given customer_id on comment table.
4. fetch all addresses of a customer by using select and given customer_id on address table.
5. fetch all past orders of a customer by using select and given customer_id on order table.
6. fetch all universities by using select on university.
7. fetch all restorants of an university by using select and given university_id on restorant table.
8. fetch all menus by using select and given restorant_id on menu table.
9. fetch all comments by using select and given restorant_id on comment table.
10. find best seller menu of a restorant by using select, join and given restorant_id on restorant and order tables.


--University
INSERT INTO university (id,name,description,city)
VALUES (1, 'İzmir Yüksek Teknoloji Enstitüsü', 'Gülbahçe Kampüsü 35430 Urla İzmir Türkiye', 'İzmir');

--Customer
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (1, 'Berkay Özkan', 'mberkayo@gmail.com', '123456', 1);
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (2, 'Mustafa Özkan', 'mustafaozkan@std.iyte.edu.tr', '123456', 1);
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (3, 'Şemsettin', 'ahmetozdemirden@std.iyte.edu.tr', '123456', 1);
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (4, 'Elif', 'elifduran@std.iyte.edu.tr', '123456', 1);
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (5, 'Uygar', 'uygaruysal@std.iyte.edu.tr', '123456', 1);
INSERT INTO customer(id, name, email, pass, university_id)
VALUES (6, 'Hüseyin', 'huseyingok@std.iyte.edu.tr', 'şifre', 1);

--Adress
INSERT INTO address(id,name,open_address,customer_id)
VALUES(1,'Evim','52/42 no:4',1);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(2,'Ofis','İnavasyon no:4',1);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(3,'Evim','15 sokak no:2',2);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(4,'Evim','5162 no:4',3);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(5,'Ev','512312 no:4',4);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(6,'Okul','512312 no:4',5);
INSERT INTO address(id,name,open_address,customer_id)
VALUES(7,'Ev','512 no:1',6);

--Credit_Card
INSERT INTO credit_card(id,name,CARDHOLDER_NAME,CARD_NUMBER,EXPIRATION_MONTH,EXPIRATION_YEAR,cvv,customer_id)
VALUES(1,'İşBankasıBanka','Mustafa Berkay Özkan','1234567891234567',12,23,123,1);
INSERT INTO credit_card(id,name,CARDHOLDER_NAME,CARD_NUMBER,EXPIRATION_MONTH,EXPIRATION_YEAR,cvv,customer_id)
VALUES(2,'TEBKartım','Hüseyin Berk Gök','1234567891234567',06,24,456,6);

--Restaurant
INSERT INTO restaurant(id,name,address,logo_url,open_hour,close_hour,minimum_price,pay_online,cash_on_delivery,card_on_delivery,owner_email,owner_password,university_id)
VALUES(1,'Rien','Gülbahçe Mahallesi, İzmir Yüksek Teknoloji Enstitüsü İnovasyon Merkezi A10 Binası 1/40, 35430 Urla/İzmir','rien.com/logo.jpg','08:00','22:00',5,0,1,1,'info@rien.com','sifre',1);
INSERT INTO restaurant(id,name,address,logo_url,open_hour,close_hour,minimum_price,pay_online,cash_on_delivery,card_on_delivery,owner_email,owner_password,university_id)
VALUES(2,'Calipso','Gülbahçe Mahallesi, 12069. Sk., 35430 Urla/İzmir','calipso.com/logo.jpg','09:00','20:00',10,1,1,1,'info@calipso.com','şifre',1);
INSERT INTO restaurant(id, name, address, logo_url, open_hour, close_hour, minimum_price, pay_online, cash_on_delivery, card_on_delivery, owner_email, owner_password, university_id)
VALUES(3,'7 de 7 Cafe','Gülbahçe Mahallesi, Gül Bahçe Cd. No:95, 35430 Urla/İzmir', 'yediyedi.com/logo.jpg', '10:00', '20:00', 10, 0, 1, 1, 'info@yediyedi.com', 'HaRdPaSsWoRd_1', 1);
INSERT INTO restaurant(id, name, address, logo_url, open_hour, close_hour, minimum_price, pay_online, cash_on_delivery, card_on_delivery, owner_email, owner_password, university_id)
VALUES(4,'AsmalıCafe','Gülbahçe Mahallesi, İzmir YTE 1-8, 35430 Urla/İzmir', 'asmalicafe.com/logo.jpg', '09:00', '21:00', 5, 0, 1, 0, 'info@asmalicafe.com', 'şifre', 1);
INSERT INTO restaurant(id, name, description, address, logo_url, open_hour, close_hour, minimum_price, pay_online, cash_on_delivery, card_on_delivery, owner_email, owner_password, university_id) --Has also decription
VALUES(5,'Atabey Kebap', 'Telefon numarası: (0232) 765 74 90', 'Gülbahçe Mahallesi, 12097. Sk. 56/!, 35430 Urla/İzmir', 'atabey.com/logo.jpg', '09:00', '23:00', 5, 1, 1, 1, 'info@atabey.com', 'şifre', 1);

--Product
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(1,'Kahvaltı','Domates, Salatalık, Beyaz Peynir, Simit veya Poğaça ile','KAHVALTI',10,'rien.com/kahvalti.jpg',1);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(2,'Köri Soslu Tavuk Salata','Akdeniz Yeşillikleri, Domates, Salatalık, Havuç, Mısır, Mor Lahana ve Köz Biber üzerinde Köri, Krema ve Mozarella ile sotelenmiş Jülyen Tavuk Parçaları','SALATA',17,'rien.com/korisoslutavuksalata.jpg',1);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(3,'Cheese Burger','El yapımı Burger Ekmeği arasında, el yapımı Köfte üzerine Cheddar Peyniri, Domates, Akdeniz Yeşillikleri, Kornişon Turşu - Patates Kızartması ile ','HAMBURGER',10,'rien.com/cheeseburger.jpg',1);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(4,'Roma Soslu Penne','Domates, Krema, Maydanoz, Kapari ve Mozarella Peynir ile sotelenmiş Julyen Tavuk Dilimleri ile soslanmış Penne Makarna','PENNE',16,'rien.com/romasoslupenne.jpg',1);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(5,'Izgara Köfte','El Yapımı Köfte – Izgara Domates, Izgara Biber -  Patates ve Blanşe Sebze ile','IZGARA',21,'rien.com/izgarakofte.jpg',1);

INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(6,'Izgara Kofte',null,'IZGARA',21,'calipso.com/izgarakofte.jpg',2);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(7,'Kahvaltı Tabağı','Beyaz peynir, tulum peyniri, yeşil zeytin, siyah zeytin, salam, tereyağı, reçel, bal, domates, salatalık, haşlanmış yumurta, 2 çay','KAHVALTI',20,'calipso.com/kahvalti.jpg',2);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(8,'Kaşarlı Sandviç',null,'SANDVIC',10,'calipso.com/kasarlisandvic.jpg',2);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(9,'Ton Balıklı Wrap','Tortilla ekmeği, ton balığı, patates, kaşar, kornişon, roka eşliğinde','WRAP',14,'calipso.com/tonbalikliwrap.jpg',2);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(10,'Calipso Special','Napolitan sos, mozzarella, kaşar peyniri, sucuk, salam, sosis, biber, zeytin, mantar, domates, mısır eşliğinde','PIZZA',25,'calipso.com/calipsospecial.jpg',2);

INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(11,'Mantı',null,'ANAYEMEK',15,'yediyedi.com/manti.jpg',3);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(12,'Sütlü tatlı',null,'TATLI',6.5,'yediyedi.com/sutlutatli.jpg',3);

INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(13,'Alfredo','Tavuk, Kaşar, Krema, Soyu Sosu, Domates Sosu','PENNE',10,'asmalicafe.com/alfredo.jpg',4);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(14,'Tepsi Tavuk','100gr Tavuk, Salata, Patates, Pilav, Barbekü, Ketçap, Mayonez, 2li Soğan Halkası, Cola','IZGARA',12.5,'asmalicafe.com/tepsitavuk.jpg',4);

INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(15,'Adana',null,'KEBAP',9,'atabey.com/adana.jpg',5);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(16,'Urfa',null,'KEBAP',9,'atabey.com/urfa.jpg',5);
INSERT INTO product(id,name,description,product_type,price,picture_url,restaurant_id)
VALUES(17,'Ayran',null,'ICECEK',2,'atabey.com/ayran.jpg',5);

--comments
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(1,'Super.',5,1,5);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(2,'Mükemmel.',5,2,4);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(3,'Efsane.',5,3,3);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(4,'Olmamış.',3,4,2);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(5,'Çok güzel.',4,5,1);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(6,'Kötü.',1,6,5);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(7,'Beğenmedim',1,1,4);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(8,'Sevmedim',2,2,3);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(9,'Tadı kötüydü.',2,3,2);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(10,'Yavaş geldi.',3,4,1);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(11,'Soğuktu',2,5,5);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(12,'Güzeldi.',4,6,4);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(13,'Vasat.',2,1,3);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(14,'Turşu eksikti.',2,2,2);
INSERT INTO comments(id,text,rating,customer_id,restaurant_id)
VALUES(15,'Patates gelmedi.',2,3,1);



SELECT avg(i.net_price)
FROM orders o, order_item oi, product p, invoice i
WHERE i.order_id = o.id and oi.order_id = o.id and p.id = oi.product_id
and o.status = 'COMPLETED'
and p.restaurant_id = 1
GROUP BY p.restaurant_id