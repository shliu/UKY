Use shliu2;

CREATE TABLE customers (
	id CHAR(3),
	last_name CHAR(20),
	first_name CHAR(20),
	balance FLOAT,
	credit_limit INT(5),
	sales_rep CHAR(2),
	PRIMARY KEY (id)
);

CREATE TABLE salesreps (
	id CHAR(2),
	last_name CHAR(20),
	first_name CHAR(20),
	commission FLOAT,
	rate FLOAT,
	PRIMARY KEY(id)
);

CREATE TABLE orders (
	id CHAR(5),
	order_date CHAR(10),
	customer_ID CHAR(5),
	PRIMARY KEY(id)
);

CREATE TABLE orderlines (
	id CHAR(5),
	part CHAR(4),
	quantity INT,
	price FLOAT,
	PRIMARY KEY(id,part)
);
