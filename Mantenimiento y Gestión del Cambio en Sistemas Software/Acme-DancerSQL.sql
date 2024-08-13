-- MySQL dump 10.13  Distrib 8.0.17, for Win64 (x86_64)
--
-- Host: localhost    Database: acme-dancer
-- ------------------------------------------------------
-- Server version	8.0.17

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `academia`
--

DROP TABLE IF EXISTS `academia`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `academia` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `apellidos` varchar(255) DEFAULT NULL,
  `correo` varchar(255) DEFAULT NULL,
  `direccionPostal` varchar(255) DEFAULT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  `telefono` varchar(255) DEFAULT NULL,
  `userAccount_id` int(11) NOT NULL,
  `nombreComercial` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `UK_r43hyh4v8a2gqh588skk25pyd` (`userAccount_id`),
  CONSTRAINT `FK_r43hyh4v8a2gqh588skk25pyd` FOREIGN KEY (`userAccount_id`) REFERENCES `useraccount` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `academia`
--

LOCK TABLES `academia` WRITE;
/*!40000 ALTER TABLE `academia` DISABLE KEYS */;
INSERT INTO `academia` VALUES (57,8,'Camacho Alvarez','correo@example.com','21711','Zacarias','34 123456789',44,'Sevilla\'s Academy'),(58,2,'Casillas Rodriguez','correoA@example.com','21700','Pedro','34 987654321',45,'Salsa Steps'),(59,0,'Camacho Cruz','correoB@example.com','21800','Luis','34 988664422',46,'Tango Place');
/*!40000 ALTER TABLE `academia` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `academia_curso`
--

DROP TABLE IF EXISTS `academia_curso`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `academia_curso` (
  `Academia_id` int(11) NOT NULL,
  `cursos_id` int(11) NOT NULL,
  UNIQUE KEY `UK_pvjcskh63u4c7h0t2s73mpds2` (`cursos_id`),
  KEY `FK_gij3badkimhcmgafluxmelbpg` (`Academia_id`),
  CONSTRAINT `FK_gij3badkimhcmgafluxmelbpg` FOREIGN KEY (`Academia_id`) REFERENCES `academia` (`id`),
  CONSTRAINT `FK_pvjcskh63u4c7h0t2s73mpds2` FOREIGN KEY (`cursos_id`) REFERENCES `curso` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `academia_curso`
--

LOCK TABLES `academia_curso` WRITE;
/*!40000 ALTER TABLE `academia_curso` DISABLE KEYS */;
INSERT INTO `academia_curso` VALUES (57,71),(57,72),(58,70);
/*!40000 ALTER TABLE `academia_curso` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `academia_solicitud`
--

DROP TABLE IF EXISTS `academia_solicitud`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `academia_solicitud` (
  `Academia_id` int(11) NOT NULL,
  `solicitudes_id` int(11) NOT NULL,
  UNIQUE KEY `UK_8x3gne99fjg40cjgd9m4co5eg` (`solicitudes_id`),
  KEY `FK_eckuk5t83xlpbs48tdtb04hc0` (`Academia_id`),
  CONSTRAINT `FK_8x3gne99fjg40cjgd9m4co5eg` FOREIGN KEY (`solicitudes_id`) REFERENCES `solicitud` (`id`),
  CONSTRAINT `FK_eckuk5t83xlpbs48tdtb04hc0` FOREIGN KEY (`Academia_id`) REFERENCES `academia` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `academia_solicitud`
--

LOCK TABLES `academia_solicitud` WRITE;
/*!40000 ALTER TABLE `academia_solicitud` DISABLE KEYS */;
INSERT INTO `academia_solicitud` VALUES (57,75),(58,73),(58,74);
/*!40000 ALTER TABLE `academia_solicitud` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `academia_tutorial`
--

DROP TABLE IF EXISTS `academia_tutorial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `academia_tutorial` (
  `Academia_id` int(11) NOT NULL,
  `tutoriales_id` int(11) NOT NULL,
  UNIQUE KEY `UK_6it5qmmfto7l6jq6ukig16l2h` (`tutoriales_id`),
  KEY `FK_a6h68dfy5y73329thnvvum78p` (`Academia_id`),
  CONSTRAINT `FK_6it5qmmfto7l6jq6ukig16l2h` FOREIGN KEY (`tutoriales_id`) REFERENCES `tutorial` (`id`),
  CONSTRAINT `FK_a6h68dfy5y73329thnvvum78p` FOREIGN KEY (`Academia_id`) REFERENCES `academia` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `academia_tutorial`
--

LOCK TABLES `academia_tutorial` WRITE;
/*!40000 ALTER TABLE `academia_tutorial` DISABLE KEYS */;
INSERT INTO `academia_tutorial` VALUES (57,47),(57,48),(58,49);
/*!40000 ALTER TABLE `academia_tutorial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `actor_actor`
--

DROP TABLE IF EXISTS `actor_actor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `actor_actor` (
  `Actor_id` int(11) NOT NULL,
  `suscritos_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `actor_actor`
--

LOCK TABLES `actor_actor` WRITE;
/*!40000 ALTER TABLE `actor_actor` DISABLE KEYS */;
INSERT INTO `actor_actor` VALUES (53,57),(54,58),(54,55),(57,54),(57,53),(57,54),(58,54),(58,53);
/*!40000 ALTER TABLE `actor_actor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `administrador`
--

DROP TABLE IF EXISTS `administrador`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `administrador` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `apellidos` varchar(255) DEFAULT NULL,
  `correo` varchar(255) DEFAULT NULL,
  `direccionPostal` varchar(255) DEFAULT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  `telefono` varchar(255) DEFAULT NULL,
  `userAccount_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `UK_gp8pvb6wijllmdmpqw9lx66wu` (`userAccount_id`),
  CONSTRAINT `FK_gp8pvb6wijllmdmpqw9lx66wu` FOREIGN KEY (`userAccount_id`) REFERENCES `useraccount` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `administrador`
--

LOCK TABLES `administrador` WRITE;
/*!40000 ALTER TABLE `administrador` DISABLE KEYS */;
INSERT INTO `administrador` VALUES (56,0,'Gonzalez Fuertes','albertoGF@gmail.com','Almonte','Alberto','34 600765123',40);
/*!40000 ALTER TABLE `administrador` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `alumno`
--

DROP TABLE IF EXISTS `alumno`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `alumno` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `apellidos` varchar(255) DEFAULT NULL,
  `correo` varchar(255) DEFAULT NULL,
  `direccionPostal` varchar(255) DEFAULT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  `telefono` varchar(255) DEFAULT NULL,
  `userAccount_id` int(11) NOT NULL,
  `tarjetaCredito_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `UK_rkoytoce3wjmvi5ttj6q6j9af` (`tarjetaCredito_id`),
  UNIQUE KEY `UK_dl831sy6dk64rw6nu6lysmgmv` (`userAccount_id`),
  CONSTRAINT `FK_dl831sy6dk64rw6nu6lysmgmv` FOREIGN KEY (`userAccount_id`) REFERENCES `useraccount` (`id`),
  CONSTRAINT `FK_rkoytoce3wjmvi5ttj6q6j9af` FOREIGN KEY (`tarjetaCredito_id`) REFERENCES `tarjeta_credito` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alumno`
--

LOCK TABLES `alumno` WRITE;
/*!40000 ALTER TABLE `alumno` DISABLE KEYS */;
INSERT INTO `alumno` VALUES (53,0,'Da-Palma Fernandez','elcorreodeismael@gmail.com','21700','Ismael','34 666666666',41,50),(54,0,'Delgado Cruz','criscorreo001@gmail.com','21007','Cristian','34 644444444',42,51),(55,0,'Jimenez Serrano','jujise36@gmail.com','21007','Juan','34 654324144',43,52);
/*!40000 ALTER TABLE `alumno` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `alumno_solicitud`
--

DROP TABLE IF EXISTS `alumno_solicitud`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `alumno_solicitud` (
  `Alumno_id` int(11) NOT NULL,
  `solicitudes_id` int(11) NOT NULL,
  UNIQUE KEY `UK_oa1t51hi85ym9fi20emgm9x6x` (`solicitudes_id`),
  KEY `FK_ri1ddi4rrl2ppq5s111uyvq4` (`Alumno_id`),
  CONSTRAINT `FK_oa1t51hi85ym9fi20emgm9x6x` FOREIGN KEY (`solicitudes_id`) REFERENCES `solicitud` (`id`),
  CONSTRAINT `FK_ri1ddi4rrl2ppq5s111uyvq4` FOREIGN KEY (`Alumno_id`) REFERENCES `alumno` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alumno_solicitud`
--

LOCK TABLES `alumno_solicitud` WRITE;
/*!40000 ALTER TABLE `alumno_solicitud` DISABLE KEYS */;
INSERT INTO `alumno_solicitud` VALUES (53,73),(53,74),(54,75);
/*!40000 ALTER TABLE `alumno_solicitud` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `comentario`
--

DROP TABLE IF EXISTS `comentario`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `comentario` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `fechaPublicacion` datetime DEFAULT NULL,
  `texto` varchar(255) DEFAULT NULL,
  `actor_id` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `comentario`
--

LOCK TABLES `comentario` WRITE;
/*!40000 ALTER TABLE `comentario` DISABLE KEYS */;
INSERT INTO `comentario` VALUES (76,0,'2024-05-05 11:30:00','Este es un comentario de ejemplo',53),(77,0,'2024-04-05 10:25:00','Este es otro comentario de ejemplo',53),(78,0,'2023-01-02 11:25:00','Mi primer comentario',54),(196608,0,'2024-06-05 00:07:55','adsa ',58),(229376,0,'2024-06-05 16:09:53','aa',57);
/*!40000 ALTER TABLE `comentario` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `curso`
--

DROP TABLE IF EXISTS `curso`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `curso` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `diaSemana` varchar(255) DEFAULT NULL,
  `fechaFin` datetime DEFAULT NULL,
  `fechaInicio` datetime DEFAULT NULL,
  `hora` time DEFAULT NULL,
  `nivel` varchar(255) DEFAULT NULL,
  `titulo` varchar(255) DEFAULT NULL,
  `estilo_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_l12m5p31kvmwky318oikci60y` (`estilo_id`),
  CONSTRAINT `FK_l12m5p31kvmwky318oikci60y` FOREIGN KEY (`estilo_id`) REFERENCES `estilo` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `curso`
--

LOCK TABLES `curso` WRITE;
/*!40000 ALTER TABLE `curso` DISABLE KEYS */;
INSERT INTO `curso` VALUES (70,0,'Lunes','2024-10-09 10:35:00','2024-05-05 11:30:00','10:00:00','Intermedio','Curso de Salsa',60),(71,0,'Miercoles','2024-12-10 12:00:00','2024-04-05 10:30:00','13:30:01','Profesional','Curso de Tango',61),(72,0,'Jueves','2024-11-11 12:00:00','2024-03-05 11:30:00','11:38:25','Principiante','Curso de Bachata',62);
/*!40000 ALTER TABLE `curso` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `estilo`
--

DROP TABLE IF EXISTS `estilo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `estilo` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `descripcion` varchar(255) DEFAULT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estilo`
--

LOCK TABLES `estilo` WRITE;
/*!40000 ALTER TABLE `estilo` DISABLE KEYS */;
INSERT INTO `estilo` VALUES (60,0,'Estilo de baile latinoamericano que se caracteriza por sus movimientos sensuales y ritmos rápidos.','Salsa'),(61,0,'Baile de origen cubano, precursor de la salsa, con movimientos más pausados.','Mambo'),(62,0,'Baile de origen dominicano conocido por su ritmo romántico y pasos sensuales.','Bachata'),(63,0,'Baile de ritmo rápido y alegre, popular en fiestas y celebraciones latinas.','Pachanga'),(64,0,'Danza española tradicional, caracterizada por su compás binario y pasos firmes.','Pasodoble'),(65,0,'Baile folclórico andaluz que se baila en pareja durante las ferias y romerías.','Sevillanas'),(66,0,'Baile argentino de pareja que se distingue por su abrazo cerrado y movimientos apasionados.','Tango'),(67,0,'Baile cubano de ritmo sincopado, conocido por sus pasos de triple tiempo.','Chachachá'),(68,0,'Baile afro-cubano caracterizado por su ritmo complejo y movimientos expresivos.','Rumba'),(69,0,'Baile angoleño conocido por su fluidez y conexión entre los bailarines.','Kizomba');
/*!40000 ALTER TABLE `estilo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `estilo_imagenes`
--

DROP TABLE IF EXISTS `estilo_imagenes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `estilo_imagenes` (
  `Estilo_id` int(11) NOT NULL,
  `imagenes` varchar(255) DEFAULT NULL,
  KEY `FK_aoim2lx139glu4ssds9b2rfhx` (`Estilo_id`),
  CONSTRAINT `FK_aoim2lx139glu4ssds9b2rfhx` FOREIGN KEY (`Estilo_id`) REFERENCES `estilo` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estilo_imagenes`
--

LOCK TABLES `estilo_imagenes` WRITE;
/*!40000 ALTER TABLE `estilo_imagenes` DISABLE KEYS */;
/*!40000 ALTER TABLE `estilo_imagenes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `estilo_videos`
--

DROP TABLE IF EXISTS `estilo_videos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `estilo_videos` (
  `Estilo_id` int(11) NOT NULL,
  `videos` varchar(255) DEFAULT NULL,
  KEY `FK_cdw3amdhkgwvaspt4mu1n2nlr` (`Estilo_id`),
  CONSTRAINT `FK_cdw3amdhkgwvaspt4mu1n2nlr` FOREIGN KEY (`Estilo_id`) REFERENCES `estilo` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estilo_videos`
--

LOCK TABLES `estilo_videos` WRITE;
/*!40000 ALTER TABLE `estilo_videos` DISABLE KEYS */;
/*!40000 ALTER TABLE `estilo_videos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hibernate_sequences`
--

DROP TABLE IF EXISTS `hibernate_sequences`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hibernate_sequences` (
  `sequence_name` varchar(255) DEFAULT NULL,
  `sequence_next_hi_value` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hibernate_sequences`
--

LOCK TABLES `hibernate_sequences` WRITE;
/*!40000 ALTER TABLE `hibernate_sequences` DISABLE KEYS */;
INSERT INTO `hibernate_sequences` VALUES ('DomainEntity',8);
/*!40000 ALTER TABLE `hibernate_sequences` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `solicitud`
--

DROP TABLE IF EXISTS `solicitud`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `solicitud` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `estado` varchar(255) DEFAULT NULL,
  `fecha` datetime DEFAULT NULL,
  `curso_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_lsb0ybudam2ceq8dghco6bltf` (`curso_id`),
  CONSTRAINT `FK_lsb0ybudam2ceq8dghco6bltf` FOREIGN KEY (`curso_id`) REFERENCES `curso` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `solicitud`
--

LOCK TABLES `solicitud` WRITE;
/*!40000 ALTER TABLE `solicitud` DISABLE KEYS */;
INSERT INTO `solicitud` VALUES (73,0,'Pendiente','2024-05-01 12:45:00',70),(74,0,'Pendiente','2024-03-02 12:35:00',70),(75,0,'Rechazado','2024-02-02 12:35:00',71);
/*!40000 ALTER TABLE `solicitud` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tarjeta_credito`
--

DROP TABLE IF EXISTS `tarjeta_credito`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tarjeta_credito` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `anio` int(11) NOT NULL,
  `codigoCVV` int(11) DEFAULT NULL,
  `marca` varchar(255) DEFAULT NULL,
  `mes` int(11) NOT NULL,
  `nombreTitular` varchar(255) DEFAULT NULL,
  `numero` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tarjeta_credito`
--

LOCK TABLES `tarjeta_credito` WRITE;
/*!40000 ALTER TABLE `tarjeta_credito` DISABLE KEYS */;
INSERT INTO `tarjeta_credito` VALUES (50,0,2025,789,'MasterCard',5,'Ismael','4603-2735-0414-7352'),(51,0,2028,370,'Visa',7,'Cristian','4891-2218-5288-1735'),(52,0,2026,529,'Visa',7,'Joao Ale','4157-1416-1570-1229');
/*!40000 ALTER TABLE `tarjeta_credito` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tutorial`
--

DROP TABLE IF EXISTS `tutorial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tutorial` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `contador` int(11) NOT NULL,
  `descripcion` varchar(255) DEFAULT NULL,
  `titulo` varchar(255) DEFAULT NULL,
  `video` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tutorial`
--

LOCK TABLES `tutorial` WRITE;
/*!40000 ALTER TABLE `tutorial` DISABLE KEYS */;
INSERT INTO `tutorial` VALUES (47,2,2,'Pasos Básicos HOMBRE para Tango Argentino','Tutorial Tango','https://www.youtube.com/watch?v=jFMQb85SZ5w'),(48,0,0,'Pasos Básicos para Tango Argentino con Pareja','Tutorial Tango para Parejas','https://www.youtube.com/watch?v=ICDoTdOe_L8'),(49,0,0,'Pasos Básicos bailar Salsa','Tutorial Salsa','https://www.youtube.com/watch?v=IbBBYxbtz-w');
/*!40000 ALTER TABLE `tutorial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `useraccount`
--

DROP TABLE IF EXISTS `useraccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `useraccount` (
  `id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `password` varchar(255) DEFAULT NULL,
  `username` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `UK_csivo9yqa08nrbkog71ycilh5` (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `useraccount`
--

LOCK TABLES `useraccount` WRITE;
/*!40000 ALTER TABLE `useraccount` DISABLE KEYS */;
INSERT INTO `useraccount` VALUES (40,0,'21232f297a57a5a743894a0e4a801fc3','administrador'),(41,0,'c6865cf98b133f1f3de596a4a2894630','alumno1'),(42,0,'c6865cf98b133f1f3de596a4a2894630','alumno2'),(43,0,'c6865cf98b133f1f3de596a4a2894630','alumno3'),(44,0,'21100e9e60400b9704419459ec2babfd','academia1'),(45,0,'21100e9e60400b9704419459ec2babfd','academia2'),(46,0,'21100e9e60400b9704419459ec2babfd','academia3');
/*!40000 ALTER TABLE `useraccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `useraccount_authorities`
--

DROP TABLE IF EXISTS `useraccount_authorities`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `useraccount_authorities` (
  `UserAccount_id` int(11) NOT NULL,
  `authority` varchar(255) DEFAULT NULL,
  KEY `FK_b63ua47r0u1m7ccc9lte2ui4r` (`UserAccount_id`),
  CONSTRAINT `FK_b63ua47r0u1m7ccc9lte2ui4r` FOREIGN KEY (`UserAccount_id`) REFERENCES `useraccount` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `useraccount_authorities`
--

LOCK TABLES `useraccount_authorities` WRITE;
/*!40000 ALTER TABLE `useraccount_authorities` DISABLE KEYS */;
INSERT INTO `useraccount_authorities` VALUES (40,'ADMINISTRADOR'),(41,'ALUMNO'),(42,'ALUMNO'),(43,'ALUMNO'),(44,'ACADEMIA'),(45,'ACADEMIA'),(46,'ACADEMIA');
/*!40000 ALTER TABLE `useraccount_authorities` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-06-05 18:00:50
