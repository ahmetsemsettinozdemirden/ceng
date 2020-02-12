-- DOWNS
DROP TABLE customer CASCADE CONSTRAINTS;
DROP TABLE address CASCADE CONSTRAINTS;
DROP TABLE credit_card CASCADE CONSTRAINTS;
DROP TABLE restaurant CASCADE CONSTRAINTS;
DROP TABLE product CASCADE CONSTRAINTS;
DROP TABLE orders CASCADE CONSTRAINTS;
DROP TABLE order_item CASCADE CONSTRAINTS;
DROP TABLE invoice CASCADE CONSTRAINTS;
DROP TABLE comments CASCADE CONSTRAINTS;
DROP TABLE university CASCADE CONSTRAINTS;

-- UPS
-- creates customer table
CREATE TABLE customer (
    id                      number(11) not null,
    email                   varchar(255) not null,
    pass                    varchar(255) not null,
    name                    varchar(64) not null,
    university_id           number(11)  not null,
    constraint pk_customer_id primary key (id),
    constraint uq_customer_email unique (email)
);

-- creates address that are connected to customer
CREATE TABLE address (
    id                      number(11)  not null,
    name                    varchar(64) not null,
    open_address            varchar(320) not null,
    customer_id             number(11) not null,
    constraint pk_address_id primary key (id)
);

-- creates credit card method which includes necessary card information
CREATE TABLE credit_card (
    id                      number(11) not null,
    name                    varchar(64) not null,
    card_number             varchar(16) not null, -- exactly 16 digits
    cardholder_name         varchar(64) not null,
    expiration_month        number(2) not null, -- exactly 2 digits (MM)
    expiration_year         number(2) not null, -- exactly 2 digits (YY)
    cvv                     number(3) not null, -- exactly 3 digits
    customer_id             number(11) not null,
    constraint pk_credit_card_id primary key (id),
    constraint ck_credit_card_month check ( expiration_month between 1 and 12 ),
    constraint ck_credit_card_year check ( expiration_year between 0 and 99 ),
    constraint ck_credit_card_cvv check ( cvv between 100 and 999 )
);

-- creates restaurant, owner info is included in restaurant table
CREATE TABLE restaurant (
    id                      number(11) not null,
    name                    varchar(64) not null,
    description             varchar(320),
    address                 varchar(320) not null,
    logo_url                varchar(320),
    open_hour               varchar(5) not null, -- HH:MM
    close_hour              varchar(5) not null, -- HH:MM
    minimum_price           float not null,
    pay_online              number(1,0) not null,
    cash_on_delivery        number(1,0) not null,
    card_on_delivery        number(1,0) not null,
    owner_email             varchar(255) not null,
    owner_password          varchar(255) not null,
    university_id           number(11) not null,
    constraint pk_restaurant_id primary key (id),
    constraint ck_restaurant_minimum_price check ( minimum_price > 0 ),
    constraint uq_restaurant_name unique (name)
);

-- creates menu
CREATE TABLE product (
    id                      number(11) not null,
    name                    varchar(64) not null,
    description             varchar(320),
    product_type            varchar(16) not null,
    price                   float not null,
    picture_url             varchar(320),
    restaurant_id           number(11) not null,
    constraint pk_product_id primary key (id),
    constraint ck_product_product_type check ( product_type in ('ANAYEMEK','KAHVALTI', 'SANDVIC', 'WRAP', 'FAJITA', 'PIZZA', 'PENNE', 'SALATA', 'IZGARA', 'KEBAP', 'HAMBURGER', 'TATLI', 'ICECEK')),
    constraint ck_product_price check ( price > 0 )
);

-- creates orders
CREATE TABLE orders (
    id                      number(11) not null,
    status                  varchar(16) not null,
    order_date              date not null,
    purchase_method         varchar(16) not null,
    customer_id             number(11) not null,
    constraint pk_orders_id primary key (id),
    constraint ck_orders_status check ( status in ('PENDING', 'PREPARING', 'SHIPPED', 'COMPLETED')),
    constraint ck_orders_purchase_method check ( purchase_method in ('PAY_ONLINE', 'CASH_ON_DELIVERY', 'CARD_ON_DELIVERY'))
);

-- creates order items, orders consist of order items which are type of product TODO: an order should contain one type of product
CREATE TABLE order_item (
    order_id                number(11) not null,
    product_id              number(11) not null,
    quantity                int not null, -- positive int
    price                   float not null, -- positive float, copied from product
    constraint ck_order_item_quantity check ( quantity > 0 ),
    constraint ck_order_item_price check ( price > 0 )
);

-- creates invoice, invoices created when ordering is completed
CREATE TABLE invoice (
    id                      number(11) not null,
    net_price               float not null,
    order_id                number(11) not null,
    constraint pk_invoice_id primary key (id),
    constraint ck_restaurant_net_price check ( net_price > 0 )
);

-- creates comments, since comment is a keyword we used comments
CREATE TABLE comments (
    id                      number(11) not null,
    text                    varchar(640) not null,
    rating                  number(1) not null, -- between 1-5 points
    customer_id             number(11) not null,
    restaurant_id           number(11) not null,
    constraint pk_comments_id primary key (id),
    constraint ck_comments_rating check ( rating between 1 and 5 )
);

-- creates university
CREATE TABLE university (
    id                      number(11) not null,
    name                    varchar(64) not null,
    description             varchar(320),
    city                    varchar(64) not null,
    constraint pk_university_id primary key (id),
    constraint uq_university_name unique (name)
);

create index ix_customer_university_id on customer (university_id);
alter table customer add constraint fk_customer_university_id foreign key (university_id) references university (id) on delete cascade;

create index ix_address_customer_id on address (customer_id);
alter table address add constraint fk_address_customer_id foreign key (customer_id) references customer (id) on delete cascade;

create index ix_credit_card_customer_id on credit_card (customer_id);
alter table credit_card add constraint fk_credit_card_customer_id foreign key (customer_id) references customer (id) on delete cascade;

create index ix_restaurant_university_id on restaurant (university_id);
alter table restaurant add constraint fk_restaurant_university_id foreign key (university_id) references university (id) on delete cascade;

create index ix_product_restaurant_id on product (restaurant_id);
alter table product add constraint fk_product_restaurant_id foreign key (restaurant_id) references restaurant (id) on delete cascade;

create index ix_orders_customer_id on orders (customer_id);
alter table orders add constraint fk_orders_customer_id foreign key (customer_id) references customer (id) on delete cascade;

create index ix_order_item_order_id on order_item (order_id);
alter table order_item add constraint fk_order_item_order_id foreign key (order_id) references orders (id) on delete cascade;

create index ix_order_item_product_id on order_item (product_id);
alter table order_item add constraint fk_order_item_product_id foreign key (product_id) references product (id) on delete cascade;

create index ix_invoice_order_id on invoice (order_id);
alter table invoice add constraint fk_invoice_order_id foreign key (order_id) references orders (id) on delete cascade;

create index ix_comments_customer_id on comments (customer_id);
alter table comments add constraint fk_comments_customer_id foreign key (customer_id) references customer (id) on delete cascade;

create index ix_comments_restaurant_id on comments (restaurant_id);
alter table comments add constraint fk_comments_restaurant_id foreign key (restaurant_id) references restaurant (id) on delete cascade;

